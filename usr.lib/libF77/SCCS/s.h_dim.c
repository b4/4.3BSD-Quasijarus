h34564
s 00005/00001/00008
d D 5.1 85/06/07 21:55:54 kre 2 1
c Add copyright
e
s 00009/00000/00000
d D 1.1 83/01/21 11:12:59 dlw 1 0
c date and time created 83/01/21 11:12:59 by dlw
e
u
U
t
T
I 1
/*
D 2
 *	"%W%"
E 2
I 2
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W%	%G%
E 2
 */

short h_dim(a,b)
short *a, *b;
{
return( *a > *b ? *a - *b : 0);
}
E 1
