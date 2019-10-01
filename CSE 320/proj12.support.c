#include "/user/cse320/Projects/project06.support.h"
#include <stdio.h>

unsigned update( unsigned PC, unsigned IR, unsigned CPSR ){

	//Different masks to retrieve data from IR and CPSR
	unsigned int condMask = 0xf0000000;
	unsigned int categoryMask = 0x0c000000;
	unsigned int imm24Mask = 0x00ffffff;
	unsigned int check25Mask = 0x02000000;

	//Determine type of instruction
	unsigned int category = (IR & categoryMask) >> 26;
	//Branch Instruction
	if (category == 0x2)
	{
		//Check for invalid branch instruction
		if ((IR & check25Mask) >> 25 != 0x1)
		{
			return 0;
		}

		unsigned int NZCV = (CPSR & condMask) >> 28;
		unsigned int condition = (IR & condMask) >> 28;

		//Check for invalid condition code
		if (condition == 0xf)
		{
			return 0;
		}

		int conditionMet = checkCondition(condition, NZCV);
		//Branch to new location if condition is met or unconditional branch
		if (conditionMet == 1)
		{
			signed int imm24 = (IR & imm24Mask);
			imm24 = (imm24 << 8) >> 6;
			return PC + imm24;
		}
		//Increase PC sequentially if condition isn't met
		return PC + 0x4;


	}
	//Data Movement or Data Processing Instruction increase sequentially
	else if (category == 0x0 || category == 0x1)
	{
		return PC + 0x4;
	}
	//Other -- Invalid instruction
	else
	{
		return 0;
	}

}

int checkCondition(unsigned condition, unsigned NZCV)
{
	//Get individual bits from NZCV
	unsigned n = NZCV & 0x8 >> 3;
	unsigned z = NZCV & 0x4 >> 2;
	unsigned c = NZCV & 0x2 >> 1;
	unsigned v = NZCV & 0x1;

	//Unconditional -- Irrelevant
	if (condition == 0xe)
	{
		return 1;
	}
	//Equal -- Z set
	else if (condition == 0x0)
	{
		return z == 0x1;
	}
	//Not Equal -- Z clear
	else if (condition == 0x1)
	{
		return z == 0x0;
	}
	//Carry -- C set
	else if (condition == 0x2)
	{
		return c == 0x1;
	}
	//Not Carry -- C clear
	else if (condition == 0x3)
	{
		return c == 0x0;
	}
	//Negative -- N set
	else if (condition == 0x4)
	{
		return n == 0x1;
	}
	//Not Negative -- N clear
	else if (condition == 0x5)
	{
		return n == 0x0;
	}
	//Overflow -- V set
	else if (condition == 0x6)
	{
		return v == 0x1;
	}
	//Not Overflow -- V clear
	else if (condition == 0x7)
	{
		return v == 0x0;
	}
	//Unsigned Greater Than -- C set and Z clear
	else if (condition == 0x8)
	{
		return c == 0x1 && z == 0x0;
	}
	//Unsigned Less Than or Equal -- C clear or Z set
	else if (condition == 0x9)
	{
		return c == 0x0 || z == 0x1;
	}
	//Signed Greater Than or Equal -- N == V
	else if (condition == 0xa)
	{
		return n == v;
	}
	//Signed Less Than -- N != V
	else if (condition == 0xb)
	{
		return n != v;
	}
	//Signed Greater Than -- Z clear and N == V
	else if (condition == 0xc)
	{
		z == 0x0 && n == v;
	}
	//Signed Less Than or Equal -- Z set or N != V
	else if (condition == 0xd)
	{
		z == 0x1 || n != v;
	}
	return 0;
}
