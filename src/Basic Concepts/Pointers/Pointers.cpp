#include <iostream>

int main()
{int x = 1;	// Declaration and initialization.
	int y = 2; // Declaration and initialization.
	int * ip = &x;
	printf("Block 1\n");
	printf("The value of x is %d\n", x);
	printf("The value of y is %d\n", y);
	printf("The value of ip is %d\n", *ip);
	printf("The address where ip is pointing to %p\n", ip);

	x = 3;
	printf("Block 2\n");
	printf("The value of x is %d\n", x);
	printf("The value of y is %d\n", y);
	printf("The value of ip is %d\n", *ip);
	printf("The address where ip is pointing to %p\n", ip);

	ip = &y;
	printf("Block 3\n");
	printf("The value of x is %d\n", x);
	printf("The value of y is %d\n", y);
	printf("The value of ip is %d\n", *ip);
	printf("The address where ip is pointing to %p\n", ip);

	int & int_reference = y;
	printf("Block 4\n");
	printf("The value of y is %d\n", y);
	printf("The value of ip is %d\n", *ip);
	printf("The address where ip is pointing to %p\n", ip);
	printf("The value of int_address is %d\n", int_reference);

	int_reference = 4;
	printf("Block 5\n");
	printf("The value of y is %d\n", y);
	printf("The value of ip is %d\n", *ip);
	printf("The address where ip is pointing to %p\n", ip);
	printf("The value of int_address is %d\n", int_reference);


	int z = 5;
	ip = &z;
	printf("Block 6\n");
	printf("The value of x is %d\n", x);
	printf("The value of y is %d\n", y);
	printf("The value of z is %d\n", z);
	printf("The value of ip is %d\n", *ip);
	printf("The address where ip is pointing to %p\n", ip);
	printf("The value of int_address is %d\n", int_reference);

	int_reference = z; // reference is immutable !
	printf("Block 7\n");
	printf("The value of x is %d\n", x);
	printf("The value of y is %d\n", y);
	printf("The value of z is %d\n", z);
	printf("The value of ip is %d\n", *ip);
	printf("The address where ip is pointing to %p\n", ip);
	printf("The address of ip is %p\n", &ip);
	printf("The value of int_address is %d\n", int_reference);

	puts("\nEnd of the program.");

	return 0;
}