#ifdef LIBC_SCCS
	.asciz	"@(#)fnorm.s	1.1 (Berkeley/CCI) 7/2/86"
#endif LIBC_SCCS

#include <tahoemath/fp.h>
#include "DEFS.h"

ENTRY(fnorm, R2|R3|R4|R5|R6)
	movl	r0,r4		# copy to temporary.
	jneq	inr0
	movl	r1,r5
	clrl	r3		# r3 - pos of m.s.b
inr1:	ffs	r5,r6
	incl	r6
	addl2	r6,r3
	shrl	r6,r5,r5
	jneq	inr1
	cmpl	$0,r3
	jeql	retzero
	jmp	cmpshift
inr0:	movl	$32,r3
inr00:	ffs	r4,r6
	incl	r6
	addl2	r6,r3
	shrl	r6,r4,r4
	jneq	inr00

cmpshift:
				# compute the shift (r4).
	subl3	r3,$HID_R0R1,r4
	jlss	shiftr		# if less then zero we shift right.
	shlq	r4,r0,r0	# else we shift left.
	subl2	r4,r2		# uodate exponent.
	jleq	underflow	# if less then 0 (biased) it is underflow.
	jmp	combine		# go to combine exponent and fraction.
shiftr:
	mnegl	r4,r4
	shrq	r4,r0,r0	# shift right.
	addl2	r4,r2		# update exponent
	cmpl	r2,$256
	jgeq	overflow	# check for overflow.
combine:
	andl2	$CLEARHID,r0	# clear the hidden bit.
	shal	$EXPSHIFT,r2,r2	# shift the exponent to its proper place.
	orl2	r2,r0
	ret

underflow:
	callf	$4,fpunder
	ret

overflow:
	callf 	$4,fpover
	ret
retzero:
	clrl	r0
	clrl	r1
	ret
