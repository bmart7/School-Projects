/***********************************************
	Brian Martin
	Project 07
	10/25/18
 ***********************************************/
#include "/user/cse320/Projects/project07.support.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void decode( unsigned int instruction, char result[])
{
	char* mnemonics[16] = {"and", "eor", "sub", "rsb", "add", "adc", "sbc", "rsc", "tst", "teq", "cmp", "cmn", "orr", "mov", "bic", "mvn"};

	//Masks to remove values from 32-bit instruction
	unsigned int conditionMask = 0xe0000000;
	unsigned int iMask = 0x02000000;
	unsigned int opcodeMask = 0x01e00000;
	unsigned int RnMask = 0x000f0000;
	unsigned int RdMask = 0x0000f000;
	unsigned int immediateMask = 0x000000ff;
	unsigned int RmMask = 0x0000000f;

	//Check if instruction is of the correct set
	unsigned int condition = (instruction & conditionMask) >> 26;
	if (condition != 0x38)
	{
		strcpy(result, "Invalid Instruction");
		return;
	}
	//Remove values from 32-bit instruction using masks
	unsigned int iBit = (instruction & iMask) >> 25;
	unsigned int opcode = (instruction & opcodeMask) >> 21;
	unsigned int Rn = (instruction & RnMask) >> 16;
	unsigned int Rd = (instruction & RdMask) >> 12;
	unsigned int immediateVal = instruction & immediateMask;
	unsigned int Rm = instruction & RmMask;

	//Add values to char array
	sprintf(result, mnemonics[opcode]);
	sprintf(result + strlen(result), "  ");

	//Remove Rd if opcode is "tst", "teq", "cmp", or "cmn"
	if (mnemonics[opcode] != mnemonics[8] && mnemonics[opcode] != mnemonics[9] && mnemonics[opcode] != mnemonics[10] && mnemonics[opcode] != mnemonics[11])
	{
		sprintf(result + strlen(result), "r%d, ", Rd);
	}

	//Remove Rn if opcode is "mov" or "mvn"
	if (mnemonics[opcode] != mnemonics[13] && mnemonics[opcode] != mnemonics[15])
	{
		sprintf(result + strlen(result), "r%d, ", Rn);
	}
	
	//Use immediate value if i bit is 1
	if (iBit == 0x0)
	{
		sprintf(result + strlen(result), "r%d", Rm);
	}
	else
	{
		sprintf(result + strlen(result), "#0x%x", immediateVal);
	}

}
