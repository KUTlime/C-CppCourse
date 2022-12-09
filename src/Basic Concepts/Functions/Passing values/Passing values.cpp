#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

// No input value
void Func1()
{
	// Empty body
}

void Func2(int i)
{
	std::printf("Input value is: %i\n", i);
	i = 0;
	std::printf("Input value is: %i\n", i);
}

void Func3(int* i)
{
	std::printf("Input value is: %i\n", *i);
	*i = 0;
	std::printf("Input value is: %i\n", *i);
}

void Func4(int& i)
{
	std::printf("Input value is: %i\n", i);
	i = 0;
	std::printf("Input value is: %i\n", i);
}

// Immutable input parameter
void Func5(const int& i)
{
	std::printf("Input value is: %i\n", i);
	//i = 0; // compilation error
	std::printf("Input value is: %i\n", i);
}

// Common use for immutable input
void Func6(const string& str)
{
	printf("Input string is: %s\n", str.c_str());
}

void Func7()
{
	printf("Function 7\n");
	static int i = 1;
	printf("i is: %d\n", i);
	++i;
	printf("i is: %d\n", i);
}

void Func8()
{
	printf("Function 8\n");
	int i = 0;
	static int j = 3;
	printf("i(non-static: %d, j(static) is: %d\n", i, j);
	printf("i(non-static: %d, j(static) is: %d\n", ++i, ++j);
}

int main()
{
	int i = 1;
	std::printf("Input value (main) is: %i\n", i);
	Func2(i);
	std::printf("Input value (main) is: %i\n", i);
	Func3(&i);
	std::printf("Input value (main) is: %i\n", i);
	i = 2;
	std::printf("Input value (main) is: %i\n", i);
	Func4(i);
	std::printf("Input value (main) is: %i\n", i);

	Func7();
	Func7();
	Func8();
	Func8();

	std::cout << "Hello World!\n";
}

