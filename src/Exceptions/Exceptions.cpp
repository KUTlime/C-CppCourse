#include <iostream>

class DivisionByZero : public std::exception
{
};

class MyClass
{
public:
	MyClass() {};
	~MyClass() {};
	void SomeSafeMethod() noexcept {};
};

void OnePossibleNotSoGoodImplementation()
{
	int numberOfAttempts = 0;
	do
	{
		std::cout << "Please, enter denominator" << std::endl;
		double denominator = 0;
		std::cin >> denominator;
		double divisor = 0;
		std::cout << "Please, enter divisor" << std::endl;
		std::cin >> divisor;

		try
		{
			if (divisor == 0)
			{
				throw DivisionByZero();
			}
		}
		catch (const DivisionByZero& ex)
		{
			std::cout << ex.what();
			std::cout << "Division by zero is not allowed. Please update the divisor value to non-zero value." << std::endl;
			numberOfAttempts++;
			continue;
		}
		catch (const std::exception& ex)
		{

		}
		std::cout << "Result: " << denominator / divisor << std::endl;
		numberOfAttempts = 0;
	} while (numberOfAttempts < 4);
	std::cout << "Good bye!\n";
}

void BetterImplementation()
{
	std::cout << "Please, enter denominator" << std::endl;
	int denominator = 0;
	std::cin >> denominator;
	int divisor = -1;
	do
	{
		std::cout << "Please, enter divisor, the value must be non zero." << std::endl;
		std::cin >> divisor;
	} while (divisor == 0);
	std::cout << "Result: " << denominator / divisor << std::endl;
}


int main()
{
	//OnePossibleNotSoGoodImplementation();
	BetterImplementation();
}