#include "/user/cse320/Projects/project06.support.h"
#include <stdio.h>

int main()
{
	union double_precision num1;
	union double_precision num2;
	num1.irep = 0x0028000000000000;
	num2.irep = 0x0014000000000000;
	double a = add(num1.drep, num2.drep);
	printf("%f\n", a);
	union double_precision num;
	num.irep = 0x0031000000000000;
	printf("%f\n", num.drep);

	num1.irep = 0x7ff0000000000000;
	num2.drep = 1.0;
	a = add(num1.drep, num2.drep);
	printf("%f\n", a);

	num1.irep = 0x7ff0000000000001;
	num2.drep = 1.0;
	a = add(num1.drep, num2.drep);
	printf("%f\n", a);

	num1.irep = 0x0000000000000000;
	num2.drep = 1.0;
	a = add(num1.drep, num2.drep);
	printf("%f\n", a);

	num1.irep = 0x0000000000000001;
	num2.drep = 1.0;
	a = add(num1.drep, num2.drep);
	printf("%f\n", a);

	num1.drep = 1.1;
	num2.drep = 1.0;
	a = add(num1.drep, num2.drep);
	printf("%f\n", a);
}
