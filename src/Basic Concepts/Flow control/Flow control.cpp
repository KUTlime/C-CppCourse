#include <iostream>

int main()
{
	int a = 1;

	if (a == 1)
	{
		std::puts("It is zero!");
	}

	// Maybe don't use it in this way.
	// The best programmers don't use a feature just because it is possible.
	// They use the feature in the best possible way.
	if (a)
	{
		std::puts("It isn't zero.");
	}

	if (a == 0)
	{
		std::puts("Zero value!");
	}
	else
	{
		std::puts("Not a zero value.");
	}

	if (a == 0)
	{
		std::puts("Zero value!");
	}
	else if (a == 1)
	{
		std::puts("One");
	}
	else
	{
		std::puts("A value greater than 1.");
	}

	// The start of one expression
	if (a == 0) std::puts("Some true value which I print.");// The end of the expression

	// The start of one expression
	if (a == 0)
		std::puts("Some true value which I print.");// The end of the expression
	std::puts("Some other true value which I print.");   // How so? What happens here?
	// The line above is not dependent on the condition if ...
	// If no block {} is specified, the first statement (terminated by ;)
	// will be evaluated based on the condition.
	// See below. 
	if (false)
		std::puts("Some true value which I print.");
	std::puts("This will be printed anyway...");   // How so? What happens here?

	bool that_why_we_use_braces_everytime = true;

	if (that_why_we_use_braces_everytime)
	{
		std::puts("Some true value which I print.");
		std::puts("Some other true value which I print.");   // How so? What happens here?
	}

	int one_condition_only = 1;
	std::puts(one_condition_only > 0 ? "Positive value" : "Zero or negative value");

	int var_for_switch = 1;
	switch (var_for_switch)
	{
	case 1:
		std::puts("One");
		break;

	case 2:
		std::puts("Two");
		break;

	default:
		std::puts("Some unknown value");
		break;
	}

	switch (var_for_switch)
	{
	case 1:
	case 2:
		std::puts("One or two"); // This is triggered if one or two is used - merge case causes.
		break;

	default:
		std::puts("Some unknown value");
		break;
	}

	switch (var_for_switch)
	{
	case 1:
		// If I omitts break here in this case,
		// the program will execute some specific code for value 1
		// and will continue with code specific for value 2.
	case 2:
		// Execute some code specific for value 2.
		std::puts("One or two"); // This is triggered if one or two is used - merge case causes.
		break;

	default:
		std::puts("Some unknown value");
		break;
	}

	// Loops

	// While - a loop with condition at the beginning (no run is guaranteed) 
	int arr[5] = { 1,2,3,4,5 }; //C++ 11 feature
	int i = 0;

	printf("While loop\n");
	while (i < 5)
	{
		printf("element %d is %d\n", i, arr[i]);
		++i;
	}

	printf("While loop with logical OR\n");
	i = 0;
	while (i < 5)
	{
		printf("element %d is %d\n", i, arr[i]);
		++i;
	}

	printf("While loop with logical AND\n");
	while (i < 5 && i > 0)
	{
		printf("element %d is %d\n", i, arr[i]);
		++i;
	}

	// Do - While - a loop with condition at the end (one run is guaranteed) 
	i = 0;
	printf("Do-While loop\n");
	do
	{
		printf("element %d is %d\n", i, arr[i]);
		++i;
	} while (i < 5);

	printf("While loop with continue\n");
	i = 0;
	while (i < 5)
	{
		if (i == 3)
		{
			++i; // without we have endless loop.
			continue;
		}
		printf("element %d is %d\n", i, arr[i]);
		++i;
	}

	printf("While loop with break\n");
	i = 0;
	while (i < 5)
	{
		if (i == 3)
		{
			break;
		}
		printf("element %d is %d\n", i, arr[i]);
		++i;
	}

	// For loop - iteration through a container
	//for (initialization; condition; after-loop action)
	//{
	//	// some body
	//}
	printf("for loop - ascending\n");
	for (int j = 0; j < 5; j++)
	{
		printf("element %d is %d\n", j, arr[j]);
	}

	printf("for loop - descending\n");
	for (int j = 5; j > 0; j--)
	{
		printf("element %d is %d\n", j - 1, arr[j - 1]);
	}

	printf("for loop - descending (other way)\n");
	for (int j = 4; j >= 0; j--)
	{
		printf("element %d is %d\n", j, arr[j]);
	}

	printf("for loop - ascending with continue\n");
	for (int j = 0; j < 5; j++)
	{
		if (j == 3)
		{
			continue;
		}
		printf("element %d is %d\n", j, arr[j]);
	}

	printf("for loop - ascending with break\n");
	for (int j = 0; j < 5; j++)
	{
		if (j == 3)
		{
			break;
		}
		printf("element %d is %d\n", j, arr[j]);
	}

	// Some pointer arithmetic
	char str[] = "string";
	printf("Iterating through string\n");
	for (char* char_pointer = str; *char_pointer; ++char_pointer)
	{
		printf("%c\n", *char_pointer);
	}

	// Some pointer arithmetic
	printf("Iterating through string (on line)\n");
	for (char* char_pointer = str; *char_pointer; ++char_pointer)
	{
		printf("%c", *char_pointer);
	}

	// C++11 feature - range loop
	printf("\nRange loop\n");
	for (char c : str)
	{
		printf("%c", c);
	}

	printf("\nRange loop (auto use)\n");
	for (auto c : str)
	{
		printf("%c", c);
	}

	std::puts("\nEnd of the program.\n");
	return 0;
}
