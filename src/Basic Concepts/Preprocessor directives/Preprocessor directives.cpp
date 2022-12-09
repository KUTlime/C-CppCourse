#define FOO 1

#include <cstdio>
#include <iostream>
#include "conditional.h"
#include "preproc.h"

// Include problem
#include "includeA.h"
#include "includeB.h"

// Constants
#define ONE 1 // How about change it to 11 later on...
#define TWO 2
#define END_OF_PROGRAM "End of the program!\n"

#define POWER(a) ( a * a )
#define MAX(a, b) (a > b ? a : b);

// Multiline macro
#define SWAP(a,b) do  { \
a ^= b; \
b ^= a; \
a ^= b; \
} while(0);

int Increment();


int main()
{
	printf("Value of first macro is: %i\n", ONE);
	printf("Value of second macro is: %i\n", TWO);


	printf("Number is %d\n", NUMBER); // in conditional.h
	printf("Integer constant: %i\n", _iOne);

	structA a;
	structB b;

	// Some macro problem
	int x = 10;
	//printf("max of %d and %d is: %d\n", x, Increment(), MAX(x, Increment()));
	//printf("max of %d and %d is: %d\n", x, Increment(), MAX(x, Increment()));


	printf("Hel\
lo world!\n");

	int c = 1;
	int d = 2;
	MAX(c, d)
		printf("c: %d, d: %d", c, d);
	SWAP(c, d);
	printf("c: %d, d: %d", c, d);

	printf(END_OF_PROGRAM);
	std::puts(END_OF_PROGRAM);
	std::cout << END_OF_PROGRAM;

	return 0;
}


int Increment()
{
	static int i = 1;
	i += 5;
	printf("returning: %d\n", i);
	return i;
}

