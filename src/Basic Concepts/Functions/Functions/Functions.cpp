// 01 Functions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cstdio>
#include <iostream>
#include "SomeUserFunctionHeader.h" // Functions defined by user. Header file with declaration.

// Function declaration and definition 
void Func()
{
	std::cout << "Some function." << std::endl;
}

// Function declaration
void Func1();

// Function declaration and definition
void IdentifyFunction(int i)
{
	printf("Some function %i", i);
}

// Here I can use the functions from SomeUserFunctionHeader.h
void FunctionCallWrapper()
{
	SomeUserDefinedFunction();
	SomeUserDefinedFunction(5);
}

void Fuasdfasd(); // Declaration
int Add(int& a, int& b); // Declaration

int main()
{
	Fuasdfasd();
	int a = 0;
	int b = 1;
	int sum = Add(a, b);
	std::cout << "End of the program!\n";

	return 0;
}

// Definition
void Fuasdfasd() { return; }; // return; can be omitted.
int Add(const int& a, const int& b)
{
	return a + b;
};

// Function definition
void Func1()
{
	std::cout << "Some function 1." << std::endl;
}

