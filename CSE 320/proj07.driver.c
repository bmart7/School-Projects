/***********************************************
	Brian Martin
	Project 07
	10/25/18
 ***********************************************/

#include "/user/cse320/Projects/project07.support.h"
#include <stdio.h>
#include <string.h>

int main()
{
	//Test 32-bit instructions
	unsigned int test1 = 0x00000000;
	unsigned int test2 = 0xe086a007;
	unsigned int test3 = 0xe286a007;
	unsigned int test4 = 0xe2cd300a;
	unsigned int test5 = 0xe049000e;
	unsigned int test6 = 0xe106500a;
	unsigned int test7 = 0xe126500a;
	unsigned int test8 = 0xe146500a;
	unsigned int test9 = 0xe166500a;
	unsigned int test10 = 0xe1a01003;
	unsigned int test11 = 0xe1e01003;

	//Resulting char arrays for test instructions
	char result1[40];
	char result2[40];
	char result3[40];
	char result4[40];
	char result5[40];
	char result6[40];
	char result7[40];
	char result8[40];
	char result9[40];
	char result10[40];
	char result11[40];

	//implementation of decode()
	decode(test1, result1);
	printf("%s\n", result1);

	decode(test2, result2);
	printf("%s\n", result2);

	decode(test3, result3);
	printf("%s\n", result3);

	decode(test4, result4);
	printf("%s\n", result4);

	decode(test5, result5);
	printf("%s\n", result5);

	decode(test6, result6);
	printf("%s\n", result6);

	decode(test7, result7);
	printf("%s\n", result7);

	decode(test8, result8);
	printf("%s\n", result8);

	decode(test9, result9);
	printf("%s\n", result9);

	decode(test10, result10);
	printf("%s\n", result10);

	decode(test11, result11);
	printf("%s\n", result11);
}
