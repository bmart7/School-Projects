#include "/user/cse320/Projects/project06.support.h"
#include <stdio.h>
/*
	BRIAN MARTIN
	A56350138
*/
int main()
{
	//PC input
	unsigned PC = 0x00020000;

	//CSPR Values
	//Equal
	unsigned eq = 0x40000000;
	//Not equal
	unsigned neq = 0x00000000;
	//Carry
	unsigned ca = 0x20000000;
	//Not carry
	unsigned nc = 0x00000000;
	//Negative
	unsigned ne = 0x40000000;
	//Not negative
	unsigned nn = 0x50000000;
	//Overflow
	unsigned ov = 0x60000000;
	//Not Overflow
	unsigned nv = 0x70000000;
	//Unsigned greater than
	unsigned ugt = 0x80000000;
	//Unsigned less than
	unsigned ult = 0x90000000;
	//Signed greater than or equal
	unsigned sge = 0xa00000000;
	//Signed less than
	unsigned slt = 0xb0000000;
	//Signed greater than
	unsigned sgt = 0xc0000000;
	//Signed less than or equal
	unsigned sle = 0xd0000000;
	//Always
	unsigned alw = 0xe0000000;


	//Data Movement
	unsigned dm1 = 0x04000000;
	unsigned dm2 = 0x14000000;

	//Data Processing
	unsigned dp1 = 0x50000000;
	unsigned dp2 = 0x60000000;

	//Branch
	unsigned b0 = 0x0a100011;
	unsigned b1 = 0x1a000008;
	unsigned b2 = 0x2a00000c;
	unsigned b3 = 0x3a000012;
	unsigned b4 = 0x4a100008;
	unsigned b5 = 0x5a000000;
	unsigned b6 = 0x6a0000cc;
	unsigned b7 = 0x7a000000;
	unsigned b8 = 0x8a000fff;
	unsigned b9 = 0x9a000000;
	unsigned ba = 0xaa004000;
	unsigned bb = 0xba000000;
	unsigned bc = 0xca000000;
	unsigned bd = 0xda000400;
	unsigned be = 0xea000000;

	//Data Movement
	printf("\nData Movement:\n\n");

	printf("PC: %08x\nIR: %08x\nCSPR: %08x\n\n", PC, dm1, alw);
	printf("Answer: %08x\n\n", update(PC, dm1, alw));

	printf("PC: %08x\nIR: %08x\nCSPR: %08x\n\n", PC, dm2, eq);
	printf("Answer: %08x\n\n", update(PC, dm2, eq));

	//Data Processing
	printf("\nData Processing:\n\n");

	printf("PC: %08x\nIR: %08x\nCSPR: %08x\n\n", PC, dp1, alw);
	printf("Answer: %08x\n\n", update(PC, dp1, alw));

	printf("PC: %08x\nIR: %08x\nCSPR: %08x\n\n", PC, dp2, eq);
	printf("Answer: %08x\n\n", update(PC, dp2, eq));

	//Branch
	printf("\nBranch:\n\n");

	printf("PC: %08x\nIR: %08x\nCSPR: %08x\n\n", PC, b0, eq);
	printf("Answer: %08x\n\n", update(PC, b0, eq));

	printf("PC: %08x\nIR: %08x\nCSPR: %08x\n\n", PC, b1, neq);
	printf("Answer: %08x\n\n", update(PC, b1, neq));

	printf("PC: %08x\nIR: %08x\nCSPR: %08x\n\n", PC, b2, ca);
	printf("Answer: %08x\n\n", update(PC, b2, ca));

	printf("PC: %08x\nIR: %08x\nCSPR: %08x\n\n", PC, b3, nc);
	printf("Answer: %08x\n\n", update(PC, b3, nc));

	printf("PC: %08x\nIR: %08x\nCSPR: %08x\n\n", PC, b4, ne);
	printf("Answer: %08x\n\n", update(PC, b4, ne));

	printf("PC: %08x\nIR: %08x\nCSPR: %08x\n\n", PC, b5, nn);
	printf("Answer: %08x\n\n", update(PC, b5, nn));

	printf("PC: %08x\nIR: %08x\nCSPR: %08x\n\n", PC, b6, ov);
	printf("Answer: %08x\n\n", update(PC, b6, ov));

	printf("PC: %08x\nIR: %08x\nCSPR: %08x\n\n", PC, b7, nv);
	printf("Answer: %08x\n\n", update(PC, b7, nv));

	printf("PC: %08x\nIR: %08x\nCSPR: %08x\n\n", PC, b8, ugt);
	printf("Answer: %08x\n\n", update(PC, b8, ugt));

	printf("PC: %08x\nIR: %08x\nCSPR: %08x\n\n", PC, b9, ult);
	printf("Answer: %08x\n\n", update(PC, b9, ult));

	printf("PC: %08x\nIR: %08x\nCSPR: %08x\n\n", PC, ba, sge);
	printf("Answer: %08x\n\n", update(PC, ba, sge));

	printf("PC: %08x\nIR: %08x\nCSPR: %08x\n\n", PC, bb, slt);
	printf("Answer: %08x\n\n", update(PC, bb, slt));

	printf("PC: %08x\nIR: %08x\nCSPR: %08x\n\n", PC, bc, sgt);
	printf("Answer: %08x\n\n", update(PC, bc, sgt));

	printf("PC: %08x\nIR: %08x\nCSPR: %08x\n\n", PC, bd, sle);
	printf("Answer: %08x\n\n", update(PC, bd, sle));

	printf("PC: %08x\nIR: %08x\nCSPR: %08x\n\n", PC, be, alw);
	printf("Answer: %08x\n\n", update(PC, be, alw));

	printf("PC: %08x\nIR: %08x\nCSPR: %08x\n\n", PC, b0, neq);
	printf("Answer: %08x\n\n", update(PC, b0, neq));


}
