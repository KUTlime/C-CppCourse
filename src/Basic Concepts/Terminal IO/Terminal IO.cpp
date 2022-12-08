#include <iostream>
#include <string>

struct MyStruct
{
};

int main()
{
	std::cout << "Hello World!\n";
	std::cout << "Hello World!" << std::endl;

	std::cout << "Hello world!" << 2 * 7 << std::endl;
	MyStruct mystruct;

	std::cout << mystruct; //Won't work, but we will show how to make it work.

	
	int i = 0; // Its better to assign some value.
	std::cin >> i;
	
	std::string str;
	std::getline(std::cin, str);
	int finalNumber = std::stoi(str);

	return 0;
}