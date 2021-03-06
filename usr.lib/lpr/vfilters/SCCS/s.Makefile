h46446
s 00010/00005/00106
d D 6.4 88/06/30 17:53:10 bostic 4 3
c install approved copyright notice
e
s 00009/00003/00102
d D 6.3 88/03/08 08:29:57 bostic 3 2
c add Berkeley specific header
e
s 00001/00001/00104
d D 6.2 87/11/05 09:22:11 bostic 2 1
c add chrtab.o to clean
e
s 00105/00000/00000
d D 6.1 87/11/04 20:45:01 bostic 1 0
c date and time created 87/11/04 20:45:01 by bostic
e
u
U
t
T
I 1
#
# Copyright (c) 1987 Regents of the University of California.
D 3
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 3
I 3
# All rights reserved.
E 3
#
D 3
#	%W%	(Berkeley)	%G%
E 3
I 3
# Redistribution and use in source and binary forms are permitted
D 4
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 4
I 4
# provided that the above copyright notice and this paragraph are
# duplicated in all such forms and that any documentation,
# advertising materials, and other materials related to such
# distribution and use acknowledge that the software was developed
# by the University of California, Berkeley.  The name of the
# University may not be used to endorse or promote products derived
# from this software without specific prior written permission.
# THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
# IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
# WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 4
#
#	%W% (Berkeley) %G%
E 3
#
CFLAGS=	-O
LIBC=	/lib/libc.a
SRCS=	necf.c railmag.c rvcat.c rvsort.c sidebyside.c vcat.c \
	vdmp.c vpf.c vplotf.c vpltdmp.c vpsf.c vsort.c
OBJS=	necf.o railmag.o rvcat.o rvsort.o sidebyside.o vcat.o \
	vdmp.o vpf.o vplotf.o vpltdmp.o vpsf.o vsort.o
ALL=	necf railmag rvcat rvsort sidebyside vcat \
	vdmp vpf vplotf vpltdmp vpsf vsort

all: ${ALL}

necf: ${LIBC}
	${CC} -O -o $@ necf.c
railmag: ${LIBC}
	${CC} -O -o $@ railmag.c
rvcat: ${LIBC}
	${CC} -O -o $@ rvcat.c
rvsort: ${LIBC}
	${CC} -O -o $@ rvsort.c
sidebyside: ${LIBC}
	${CC} -O -o $@ sidebyside.c
vcat: ${LIBC}
	${CC} -O -o $@ vcat.c
vdmp: ${LIBC}
	${CC} -O -o $@ vdmp.c
vpf: ${LIBC}
	${CC} -O -o $@ vpf.c
vplotf: ${LIBC} chrtab.c
	${CC} -O -o $@ vplotf.c chrtab.c
vpltdmp: ${LIBC}
	${CC} -O -o $@ vpltdmp.c
vpsf: ${LIBC}
	${CC} -O -o $@ vpsf.c
vsort: ${LIBC}
	${CC} -O -o $@ vsort.c

clean: FRC
D 2
	rm -f ${OBJS} core ${ALL}
E 2
I 2
	rm -f ${OBJS} core ${ALL} chrtab.o
E 2

depend: FRC
	mkdep -p ${CFLAGS} ${SRCS}

install: FRC
	install -s -o bin -g bin -m 755 necf ${DESTDIR}/usr/lib/necf
	install -s -o bin -g bin -m 755 railmag ${DESTDIR}/usr/lib/railmag
	install -s -o bin -g bin -m 755 rvcat ${DESTDIR}/usr/lib/rvcat
	install -s -o bin -g bin -m 755 rvsort ${DESTDIR}/usr/lib/rvsort
	install -s -o bin -g bin -m 755 sidebyside ${DESTDIR}/usr/lib/sidebyside
	install -s -o bin -g bin -m 755 vcat ${DESTDIR}/usr/lib/vcat
	install -s -o bin -g bin -m 755 vdmp ${DESTDIR}/usr/lib/vdmp
	install -s -o bin -g bin -m 755 vpf ${DESTDIR}/usr/lib/vpf
	rm -f ${DESTDIR}/usr/lib/vpfW
	ln ${DESTDIR}/usr/lib/vpf ${DESTDIR}/usr/lib/vpfW
	install -s -o bin -g bin -m 755 vplotf ${DESTDIR}/usr/lib/vplotf
	install -s -o bin -g bin -m 755 vpltdmp ${DESTDIR}/usr/lib/vpltdmp
	install -s -o bin -g bin -m 755 vpsf ${DESTDIR}/usr/lib/vpsf
	install -s -o bin -g bin -m 755 vsort ${DESTDIR}/usr/lib/vsort

lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

necf: necf.c /usr/include/stdio.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
necf: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
railmag: railmag.c
rvcat: rvcat.c /usr/include/stdio.h /usr/include/sys/vcmd.h
rvcat: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
rvcat: /usr/include/sys/ttydev.h /usr/include/vfont.h
rvsort: rvsort.c /usr/include/stdio.h
sidebyside: sidebyside.c /usr/include/stdio.h
vcat: vcat.c /usr/include/stdio.h /usr/include/sys/vcmd.h
vcat: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
vcat: /usr/include/sys/ttydev.h /usr/include/vfont.h
vdmp: vdmp.c /usr/include/stdio.h /usr/include/sys/vcmd.h
vdmp: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
vdmp: /usr/include/sys/ttydev.h
vpf: vpf.c /usr/include/signal.h /usr/include/machine/trap.h
vpf: /usr/include/stdio.h /usr/include/sys/vcmd.h /usr/include/sys/ioctl.h
vpf: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
vplotf: vplotf.c /usr/include/stdio.h /usr/include/vfont.h
vplotf: /usr/include/sys/vcmd.h /usr/include/sys/ioctl.h
vplotf: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
vpltdmp: vpltdmp.c /usr/include/stdio.h /usr/include/sys/vcmd.h
vpltdmp: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
vpltdmp: /usr/include/sys/ttydev.h
vpsf: vpsf.c /usr/include/stdio.h /usr/include/sys/vcmd.h
vpsf: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
vpsf: /usr/include/sys/ttydev.h
vsort: vsort.c /usr/include/stdio.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 1
