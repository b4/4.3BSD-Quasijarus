/*	Amovzb.c	1.1	86/07/20	*/

#include "../tahoealign/align.h" 
movzb(infop) 	process_info *infop;
/*
/*	Move byte to word or longword, zero-extended
/*
/****************************************/
{
	register long result;
	register struct oprnd *oppnt;

	oppnt = operand(infop,0);
	result = oppnt->data;
	negative_0;
	if (result == 0 )  zero_1 ; else zero_0;
	overflow_0;  carry_1;
	if ((oppnt->mode & 0xff) == Dir) 
		write_back (infop, result , operand(infop,1) );
	else write_back (infop, result & 0xff, operand(infop,1) );
}
