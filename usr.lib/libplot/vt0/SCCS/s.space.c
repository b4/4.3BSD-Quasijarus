h45051
s 00002/00002/00018
d D 4.2 83/11/10 15:24:07 ralph 2 1
c fixed warning messages
e
s 00020/00000/00000
d D 4.1 83/06/27 14:26:21 sam 1 0
c date and time created 83/06/27 14:26:21 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

extern float boty;
extern float botx;
extern float oboty;
extern float obotx;
extern float scalex;
extern float scaley;
D 2
float deltx 4095.;
float delty 4095.;
E 2
I 2
float deltx = 4095.;
float delty = 4095.;
E 2
space(x0,y0,x1,y1){
	botx = -2047.;
	boty = -2047;
	obotx = x0;
	oboty = y0;
	scalex = deltx/(x1-x0);
	scaley = delty/(y1-y0);
}
E 1
