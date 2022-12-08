#include <iostream>

int main(int argCount, char ** args)
{
    std::cout << "Number of input parameter(s): " << argCount << std::endl;

	for (size_t i = 0; i < argCount; i++)
	{
		std::cout << args[i] << std::endl;
	}
}
