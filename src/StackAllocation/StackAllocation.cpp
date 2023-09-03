// StackAllocation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void AllocateStackMemory(const int& n)
{
    auto ptr = alloca(n);
	std::string result = (ptr == nullptr) ? "unsuccessful" : "successful.";
	std::cout << "Allocation for " << n << " has been " << result << std::endl;
}

int main()
{
	for (size_t i = 0; i < 10*1024*1024; i++)
	{
		try
		{
			AllocateStackMemory(i);
		}
		catch (const std::exception&)
		{
			std::cout << "Exception on n: " << i << std::endl;
		}
	}
}