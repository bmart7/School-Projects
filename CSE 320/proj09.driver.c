/******************************************************************************
 Project #9 Driver Module
 Name: Brian Martin
 APID: A56350138
 C source code for the calling of functions negate, absolute, add, sub,
 mul, divide, power, and factorial
******************************************************************************/

#include "/user/cse320/Projects/project09.support.h"
#include <stdio.h>

int main()
{
	//Testing for negate( int N )

	printf("\nTests for negate( int N ):\n");

	//Initialization of testing parameters

	int negA = 70;
	int negB = 0;
	int negC = -4;
	int negD = 0x00000001;

	//Calls to negate( int N )

	printf("\nParameter(s): (%d)\n", negA);

	negA = negate(negA);
	printf("%d\n", negA);

	printf("\nParameter(s): (%d)\n", negB);

	negB = negate(negB);
	printf("%d\n", negB);

	printf("\nParameter(s): (%d)\n", negC);

	negC = negate(negC);
	printf("%d\n", negC);

	printf("\nParameter(s): (%d)\n", negD);

	negD = negate(negD);
	printf("%d\n", negD);


	//Testing for absolute( int N )

	printf("\nTests for absolute( int N ):\n");

	//Initialization for testing parameters

	int absA = 1;
	int absB = -1;
	int absC = 0;
	int absD = 0x80000001;

	//calls to absolute( int N )

	printf("\nParameter(s): (%d)\n", absA);

	absA = absolute(absA);
	printf("%d\n", absA);

	printf("\nParameter(s): (%d)\n", absB);

	absB = absolute(absB);
	printf("%d\n", absB);

	printf("\nParameter(s): (%d)\n", absC);

	absC = absolute(absC);
	printf("%d\n", absC);

	printf("\nParameter(s): (%d)\n", absD);

	absD = absolute(absD);
	printf("%d\n", absD);


	//Testing for add( int A, int B )

	printf("\nTests for add( int A, int B ):\n");

	//Initialization of testing parameters

	int addA = 1;
	int addB = -1;
	int addC = 0x7fffffff;
	int addD = 0x80000000;

	//Calls to add( int A, int B )

	printf("\nParameter(s): (%d, %d)\n", addA, addA);

	int addResA = add(addA, addA);
	printf("%d\n", addResA);

	printf("\nParameter(s): (%d, %d)\n", addB, addB);

	int addResB = add(addB, addB);
	printf("%d\n", addResB);

	printf("\nParameter(s): (%d, %d)\n", addA, addB);

	int addResC = add(addA, addB);
	printf("%d\n", addResC);

	printf("\nParameter(s): (%d, %d)\n", addC, addA);

	int addResD = add(addC, addA);
	printf("%d\n", addResD);

	printf("\nParameter(s): (%d, %d)\n", addD, addB);

	int addResE = add(addD, addB);
	printf("%d\n", addResE);


	//Testing for sub( int A, int B )

	printf("\nTests for sub( int A, int B ):\n");

	//Initialization of testing parameters

	int subA = 1;
	int subB = -2;
	int subC = 0x7fffffff;
	int subD = 0x80000000;

	//Calls to sub( int A, int B )

	printf("\nParameter(s): (%d, %d)\n", subA, subA);

	int subResA = sub(subA, subA);
	printf("%d\n", subResA);

	printf("\nParameter(s): (%d, %d)\n", subB, subB);

	int subResB = sub(subB, subB);
	printf("%d\n", subResB);

	printf("\nParameter(s): (%d, %d)\n", subA, subB);

	int subResC = sub(subA, subB);
	printf("%d\n", subResC);

	printf("\nParameter(s): (%d, %d)\n", subC, subB);

	int subResD = sub(subC, subB);
	printf("%d\n", subResD);

	printf("\nParameter(s): (%d, %d)\n", subD, subA);

	int subResE = sub(subD, subA);
	printf("%d\n", subResE);


	//Testing for mul( int A, int B )

	printf("\nTests for mul( int A, int B ):\n");

	//Initialization of testing parameters

	int mulA = 2;
	int mulB = -1;
	int mulC = 0x7fffffff;
	int mulD = 0x80000000;

	//Calls to mul( int A, int B )

	printf("\nParameter(s): (%d, %d)\n", mulA, mulA);

	int mulResA = mul(mulA, mulA);
	printf("%d\n", mulResA);

	printf("\nParameter(s): (%d, %d)\n", mulB, mulB);

	int mulResB = mul(mulB, mulB);
	printf("%d\n", mulResB);

	printf("\nParameter(s): (%d, %d)\n", mulA, mulB);

	int mulResC = mul(mulA, mulB);
	printf("%d\n", mulResC);

	printf("\nParameter(s): (%d, %d)\n", mulC, mulA);

	int mulResD = mul(mulC, mulA);
	printf("%d\n", mulResD);

	printf("\nParameter(s): (%d, %d)\n", mulD, mulA);

	int mulResE = mul(mulD, mulA);
	printf("%d\n", mulResE);


	//Testing for divide( int A, int B )

	printf("\nTests for divide( int A, int B ):\n");

	//Initialization for testing parameters

	int divA = 1;
	int divB = 2;
	int divC = 40;
	int divD = -1;

	//Calls to divide( int A, int B )

	printf("\nParameter(s): (%d, %d)\n", divA, divA);

	int divResA = divide(divA, divA);
	printf("%d\n", divResA);

	printf("\nParameter(s): (%d, %d)\n", divB, divA);

	int divResB = divide(divB, divA);
	printf("%d\n", divResB);

	printf("\nParameter(s): (%d, %d)\n", divC, divB);

	int divResC = divide(divC, divB);
	printf("%d\n", divResC);

	printf("\nParameter(s): (%d, %d)\n", divC, divD);

	int divResD = divide(divC, divD);
	printf("%d\n", divResD);

	printf("\nParameter(s): (%d, %d)\n", divD, divA);

	int divResE = divide(divD, divA);
	printf("%d\n", divResE);


	//Testing for power( int n, int I )

	printf("\nTests for power( int N, int I ):\n");

	//Initialization for testing parameters

	int powA = 1;
	int powB = 2;
	int powC = 40;
	int powD = -2;
	int powE = 100000;
	int powF = 0;

	//Calls to power( int N, int I )

	printf("\nParameter(s): (%d, %d)\n", powB, powF);

	int powResA = power(powB, powF);
	printf("%d\n", powResA);

	printf("\nParameter(s): (%d, %d)\n", powC, powB);

	int powResB = power(powC, powB);
	printf("%d\n", powResB);

	printf("\nParameter(s): (%d, %d)\n", powD, powA);

	int powResC = power(powD, powA);
	printf("%d\n", powResC);

	printf("\nParameter(s): (%d, %d)\n", powD, powB);

	int powResD = power(powD, powB);
	printf("%d\n", powResD);

	printf("\nParameter(s): (%d, %d)\n", powA, powD);

	int powResE = power(powA, powD);
	printf("%d\n", powResE);

	printf("\nParameter(s): (%d, %d)\n", powC, powE);

	int powResF = power(powC, powE);
	printf("%d\n", powResF);


	//Testing for factorial( int N )

	printf("\nTests for factorial( int N ):\n");

	//Initialization of testing parameters

	int facA = 0;
	int facB = 1;
	int facC = 4;
	int facD = 400;
	int facE = -1;

	//Calls to factorial( int N )

	printf("\nParameter(s): (%d)\n", facA);

	int facResA = factorial(facA);
	printf("%d\n", facResA);

	printf("\nParameter(s): (%d)\n", facB);

	int facResB = factorial(facB);
	printf("%d\n", facResB);

	printf("\nParameter(s): (%d)\n", facC);

	int facResC = factorial(facC);
	printf("%d\n", facResC);

	printf("\nParameter(s): (%d)\n", facD);

	int facResD = factorial(facD);
	printf("%d\n", facResD);

	printf("\nParameter(s): (%d)\n", facE);

	int facResE = factorial(facE);
	printf("%d\n", facResE);
}
