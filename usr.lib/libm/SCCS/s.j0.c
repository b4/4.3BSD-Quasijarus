h58485
s 00008/00003/00195
d D 5.2 88/04/29 12:18:42 bostic 5 4
c add Berkeley copyright; NOTE: this code is AT&T derived!
e
s 00000/00000/00198
d D 5.1 87/11/30 18:34:00 bostic 4 3
c tahoe release
e
s 00007/00007/00191
d D 1.3 87/07/13 19:20:36 zliu 3 2
c clean-ups.
e
s 00002/00001/00196
d D 1.2 85/09/11 23:54:06 elefunt 2 1
c 4.3BSD version dated 09/11/85.
e
s 00197/00000/00000
d D 1.1 85/09/06 17:52:52 zliu 1 0
c date and time created 85/09/06 17:52:52 by zliu
e
u
U
t
T
I 5
/*
 * Copyright (c) 1985 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 5
I 1
#ifndef lint
D 2
static char sccsid[] = "%W% (ELEFUNT) %G%";
E 2
I 2
D 5
static char sccsid[] =
"%Z%%M%	4.2 (Berkeley) 8/21/85; %I% (ucb.elefunt) %G%";
E 2
D 3
#endif not lint
E 3
I 3
#endif	/* not lint */
E 5
I 5
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 5
E 3

/*
	floating point Bessel's function
	of the first and second kinds
	of order zero

	j0(x) returns the value of J0(x)
	for all real values of x.

	There are no error returns.
	Calls sin, cos, sqrt.

	There is a niggling bug in J0 which
	causes errors up to 2e-16 for x in the
	interval [-8,8].
	The bug is caused by an inappropriate order
	of summation of the series.  rhm will fix it
	someday.

	Coefficients are from Hart & Cheney.
	#5849 (19.22D)
	#6549 (19.25D)
	#6949 (19.41D)

	y0(x) returns the value of Y0(x)
	for positive real values of x.
	For x<=0, if on the VAX, error number EDOM is set and
	the reserved operand fault is generated;
	otherwise (an IEEE machine) an invalid operation is performed.

	Calls sin, cos, sqrt, log, j0.

	The values of Y0 have not been checked
	to more than ten places.

	Coefficients are from Hart & Cheney.
	#6245 (18.78D)
	#6549 (19.25D)
	#6949 (19.41D)
*/

#include <math.h>
D 3
#ifdef VAX
E 3
I 3
#if defined(vax)||defined(tahoe)
E 3
#include <errno.h>
D 3
#else	/* IEEE double */
E 3
I 3
#else	/* defined(vax)||defined(tahoe) */
E 3
static double zero = 0.e0;
D 3
#endif
E 3
I 3
#endif	/* defined(vax)||defined(tahoe) */
E 3
static double pzero, qzero;
static double tpi	= .6366197723675813430755350535e0;
static double pio4	= .7853981633974483096156608458e0;
static double p1[] = {
	0.4933787251794133561816813446e21,
	-.1179157629107610536038440800e21,
	0.6382059341072356562289432465e19,
	-.1367620353088171386865416609e18,
	0.1434354939140344111664316553e16,
	-.8085222034853793871199468171e13,
	0.2507158285536881945555156435e11,
	-.4050412371833132706360663322e8,
	0.2685786856980014981415848441e5,
};
static double q1[] = {
	0.4933787251794133562113278438e21,
	0.5428918384092285160200195092e19,
	0.3024635616709462698627330784e17,
	0.1127756739679798507056031594e15,
	0.3123043114941213172572469442e12,
	0.6699987672982239671814028660e9,
	0.1114636098462985378182402543e7,
	0.1363063652328970604442810507e4,
	1.0
};
static double p2[] = {
	0.5393485083869438325262122897e7,
	0.1233238476817638145232406055e8,
	0.8413041456550439208464315611e7,
	0.2016135283049983642487182349e7,
	0.1539826532623911470917825993e6,
	0.2485271928957404011288128951e4,
	0.0,
};
static double q2[] = {
	0.5393485083869438325560444960e7,
	0.1233831022786324960844856182e8,
	0.8426449050629797331554404810e7,
	0.2025066801570134013891035236e7,
	0.1560017276940030940592769933e6,
	0.2615700736920839685159081813e4,
	1.0,
};
static double p3[] = {
	-.3984617357595222463506790588e4,
	-.1038141698748464093880530341e5,
	-.8239066313485606568803548860e4,
	-.2365956170779108192723612816e4,
	-.2262630641933704113967255053e3,
	-.4887199395841261531199129300e1,
	0.0,
};
static double q3[] = {
	0.2550155108860942382983170882e6,
	0.6667454239319826986004038103e6,
	0.5332913634216897168722255057e6,
	0.1560213206679291652539287109e6,
	0.1570489191515395519392882766e5,
	0.4087714673983499223402830260e3,
	1.0,
};
static double p4[] = {
	-.2750286678629109583701933175e20,
	0.6587473275719554925999402049e20,
	-.5247065581112764941297350814e19,
	0.1375624316399344078571335453e18,
	-.1648605817185729473122082537e16,
	0.1025520859686394284509167421e14,
	-.3436371222979040378171030138e11,
	0.5915213465686889654273830069e8,
	-.4137035497933148554125235152e5,
};
static double q4[] = {
	0.3726458838986165881989980e21,
	0.4192417043410839973904769661e19,
	0.2392883043499781857439356652e17,
	0.9162038034075185262489147968e14,
	0.2613065755041081249568482092e12,
	0.5795122640700729537480087915e9,
	0.1001702641288906265666651753e7,
	0.1282452772478993804176329391e4,
	1.0,
};

double
j0(arg) double arg;{
	double argsq, n, d;
	double sin(), cos(), sqrt();
	int i;

	if(arg < 0.) arg = -arg;
	if(arg > 8.){
		asympt(arg);
		n = arg - pio4;
		return(sqrt(tpi/arg)*(pzero*cos(n) - qzero*sin(n)));
	}
	argsq = arg*arg;
	for(n=0,d=0,i=8;i>=0;i--){
		n = n*argsq + p1[i];
		d = d*argsq + q1[i];
	}
	return(n/d);
}

double
y0(arg) double arg;{
	double argsq, n, d;
	double sin(), cos(), sqrt(), log(), j0();
	int i;

	if(arg <= 0.){
D 3
#ifdef VAX
E 3
I 3
#if defined(vax)||defined(tahoe)
E 3
		extern double infnan();
		return(infnan(EDOM));		/* NaN */
D 3
#else	/* IEEE double */
E 3
I 3
#else	/* defined(vax)||defined(tahoe) */
E 3
		return(zero/zero);	/* IEEE machines: invalid operation */
D 3
#endif
E 3
I 3
#endif	/* defined(vax)||defined(tahoe) */
E 3
	}
	if(arg > 8.){
		asympt(arg);
		n = arg - pio4;
		return(sqrt(tpi/arg)*(pzero*sin(n) + qzero*cos(n)));
	}
	argsq = arg*arg;
	for(n=0,d=0,i=8;i>=0;i--){
		n = n*argsq + p4[i];
		d = d*argsq + q4[i];
	}
	return(n/d + tpi*j0(arg)*log(arg));
}

static
asympt(arg) double arg;{
	double zsq, n, d;
	int i;
	zsq = 64./(arg*arg);
	for(n=0,d=0,i=6;i>=0;i--){
		n = n*zsq + p2[i];
		d = d*zsq + q2[i];
	}
	pzero = n/d;
	for(n=0,d=0,i=6;i>=0;i--){
		n = n*zsq + p3[i];
		d = d*zsq + q3[i];
	}
	qzero = (8./arg)*(n/d);
}
E 1