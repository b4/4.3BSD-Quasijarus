h57767
s 00007/00003/00011
d D 5.1 85/06/06 16:17:32 dist 3 2
c Add copyright
e
s 00001/00001/00013
d D 1.2 82/01/18 21:56:01 linton 2 1
c sccsid
e
s 00014/00000/00000
d D 1.1 82/01/18 19:20:33 linton 1 0
c date and time created 82/01/18 19:20:33 by linton
e
u
U
t
T
I 1
D 3
/* Copyright (c) 1982 Regents of the University of California */

D 2
static char sccsid[] = "%Z%%M% %I% %G%";
E 2
I 2
/* static char sccsid[] = "%Z%%M% %I% %G%"; */
E 3
I 3
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 3
E 2

/*
 * definition of line number information table
 */

typedef struct {
	LINENO line;
	ADDRESS addr;
} LINETAB;

LINETAB *linetab;
E 1
