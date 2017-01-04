h59329
s 00022/00000/00000
d D 1.1 86/07/20 11:13:55 sam 1 0
c date and time created 86/07/20 11:13:55 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#include "../tahoealign/align.h" 
aoblss(infop)	process_info *infop;
/*
/*	Add one, branch if less than.
/*	Can't use real HW opcode, don't want to branch out of here !
/*
/*******************************************/
{
	register long limit, index, new_address, complement;

	limit = operand(infop,0)->data;
	index = operand(infop,1)->data;
	complement =  limit + ~index;
	if ( complement < 0){ carry_0; negative_1;}else{carry_1; negative_0;}
	if ( complement == 0) zero_1; else zero_0;
	overflow_0;
	write_back (infop,index+1, operand(infop,1));
	new_address = operand(infop,2)->address;
	if (!negative && !zero) pc = new_address;
}
E 1
