#include <iostream>
#include "InternationalPhonePrefixValidator.h"
#include "PhoneNumberApp.h"
#include "PrefixFactory.h"

int OldImplementationWithoutPolymorphism()
{
	InternationalPhonePrefixValidator validator;
	std::cout << "Enter the country code: " << std::endl;
	int input;
	std::cin >> input;
	auto result = validator.Validate(input);

	if (result.has_value())
	{
		std::cout << "The parsing has been succesfull.";
		std::cout << result.value();
		std::string s = result.value();
		std::cout << "The string casted prefix: " << s << std::endl;
		return 0;
	}
	std::cout << "Your input was not recognized as a valid international prefix." << std::endl;
	return -1;
}

int main()
{
	PrefixFactory factory;
	std::cout << "Enter the country code: " << std::endl;
	int input;
	std::cin >> input;
	auto result = factory.Create(input);

	if (result.has_value())
	{
		std::cout << "The parsing has been succesfull.";
		std::cout << result.value();
		std::string s = result.value();
		std::cout << "The string casted prefix: " << s << std::endl;
		return 0;
	}
	std::cout << "Your input was not recognized as a valid international prefix." << std::endl;
	return -1;
}

