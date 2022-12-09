#include <iostream>

// Declarations
int Factorial(const int& n);
long double FactorialDouble(const int& n);
int Get_value_from_user();
int Get_upper_bound_from_user();
int Get_value_from_user_with_message(const char* message);
void Get_maximal_factorial_n();


int main()
{
	Get_maximal_factorial_n();
	std::cout << "End of the program!\n";
}

// Definition of functions
int Get_value_from_user()
{
	return Get_value_from_user_with_message("Give me some n for factorial: ");
};

int Get_upper_bound_from_user()
{
	return Get_value_from_user_with_message("Give me some factorial upper bound for n: ");
};

int Get_value_from_user_with_message(const char* message)
{
	int n;
	std::cout << message;
	std::cin >> n;
	return n;
};

int Factorial(const int& n)
{
	int result = 1;
	if (n < 0)
	{
		// Do nothing, return 1
	}
	for (int i = n; i > 0; --i)
	{
		result *= i;
	}
	return result;
};

long double FactorialDouble(const int& n)
{
	long double result = 1.0;
	if (n < 0)
	{
		// Do nothing, return 1
	}
	for (int i = n; i > 0; --i)
	{
		result *= i;
	}
	return result;
};

void Get_maximal_factorial_n()
{
	int upper_bound = Get_upper_bound_from_user();
	for (int i = 0; i <= upper_bound; ++i)
	{
		long double factorial = FactorialDouble(i);
		if (isinf(factorial))
		{
			std::cout << "The maximum number for factorial is " << --i << std::endl;
			break;
		}
		std::cout << "Factorial of n(" << i << ") is " << factorial << std::endl;
	}
}
