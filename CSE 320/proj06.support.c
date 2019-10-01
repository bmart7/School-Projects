#include "/user/cse320/Projects/project06.support.h"
#include <stdio.h>
double add( double num1, double num2 )
{
	union double_precision a;
	union double_precision b;
	a.drep = num1;
	b.drep = num2;

	unsigned long long int signA = (a.irep & 0x8000000000000000) >> 63;
	unsigned long long int signB = (b.irep & 0x8000000000000000) >> 63;
	unsigned long long int biasedA = (a.irep >> 52) & 0x7ff;
	unsigned long long int biasedB = (b.irep >> 52) & 0x7ff;
	unsigned long long int fractionA = a.irep & 0xfffffffffffff;
	unsigned long long int fractionB = b.irep & 0xfffffffffffff;

	if (biasedA == 0x7ff || biasedB == 0x7ff)
	{
		if (biasedA == 0x7ff)
		{
			return num1;
		}
		else
		{
			return num2;
		}
	}
	else if (biasedA == 0x0 || biasedB == 0x0)
	{
		if (biasedA == 0x0)
		{
			return num2;
		}
		else
		{
			return num1;
		}
	}

	if (signA == 0x1)
	{
		fractionA = ~fractionA;
	}
	if (signB == 0x1)
	{
		fractionB = ~fractionB;
	}

	if (biasedB > biasedA)
	{
		unsigned long long int temp;
		temp = biasedA;
		biasedA = biasedB;
		biasedB = temp;
		temp = fractionA;
		fractionA = fractionB;
		fractionB = temp;
		temp = signA;
		signA = signB;
		signB = temp;
	}

	fractionA = fractionA | 0x10000000000000;
	fractionB = fractionB | 0x10000000000000;
	unsigned long long int expDif = biasedA - biasedB;
	fractionB = fractionB >> expDif;
	
	unsigned long long int fractionC = fractionA + fractionB;
	unsigned long long int overflow = fractionC >> 53;
	unsigned long long int beforeDec = (fractionC >> 52) & 0x1;
	unsigned long long int expC = biasedA;
	int count = 0;

	if (overflow != 0x0)
	{
		unsigned long long int temp = overflow;

		while ((temp >> 63) != 0x1)
		{
			temp = temp << 1;
			count++;
		}
		count = 64 - count;
		
		fractionC = fractionC >> count;
		expC = expC + count;
	}

	fractionC = fractionC & 0xfffffffffffff;

	expC = (expC & 0x7ff) << 52;
	if (signA > signB)
	{
		fractionC = ~fractionC;
	}
	unsigned long long int total = expC | fractionC;
	union double_precision result;
	result.irep = total;
	if (signA > signB)
	{
		result.drep = -result.drep;
	}
	return result.drep;

}
