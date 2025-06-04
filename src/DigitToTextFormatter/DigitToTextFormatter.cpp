#include <iostream>
#include <string>

template <typename T>
std::string NumberToText(T const & num)
{
	static_assert(std::is_integral<T>::value, "Integral required.");
	switch (num)
	{
		case 0: return "Zero";
		case 1: return "One";
		case 2: return "Two";
		case 3: return "Three";
		case 4: return "Four";
		case 5: return "Five";
		case 6: return "Six";
		case 7: return "Seven";
		case 8: return "Eight";
		case 9: return "Nine";
		default: return "";
	}
}

auto GetNumberFromUser(int const & lowerBound, int const & upperBound)
{
	long number = -1;
	do
	{
		std::cout << "Enter a number between 0 and 9: ";
		std::cin >> number;
		if (number < lowerBound)
		{
			std::cout << "The number should be greater or equal to zero. Please try again.\n";
		}
		if (number > upperBound) 
		{
			std::cout << "The number should be between 0 and 9. Please try again.\n";
		}
	} while (number < lowerBound || number > upperBound);

	return number;
}

class Task
{
private:
	int numberFromUser;
	std::string num;
public:
	Task& NumberToText()
	{
		switch (numberFromUser)
		{
		case 0: num = "Zero"; break;
		case 1: num = "One"; break;
		default: num = ""; break;
		}
		return *this;
	}
	Task& GetNumberFromUser(const int const& lowerBound, const int const& upperBound)
	{
		do
		{
			std::cout << "Enter a number between 0 and 9: ";
			std::cin >> numberFromUser;
			if (numberFromUser < lowerBound)
			{
				std::cout << "The number should be greater or equal to zero. Please try again.\n";
			}
			if (numberFromUser > upperBound)
			{
				std::cout << "The number should be between 0 and 9. Please try again.\n";
			}
		} while (numberFromUser < lowerBound || numberFromUser > upperBound);

		return *this;
	}
	void Print()
	{
		std::cout << num << std::endl;
	}
private:

};

int main()
{
	// Option 1
	auto input = GetNumberFromUser(0, 9);
	auto result = NumberToText(input);
	std::cout << result;

	// Minimalistic version
	std::cout << NumberToText(GetNumberFromUser(0, 9));

	// Fluent API
	Task execute;
	execute
		.GetNumberFromUser(0, 9)
		.NumberToText()
		.Print()
		;

	// Test error
	auto val = NumberToText("asdfsadf");
	return 0;
}