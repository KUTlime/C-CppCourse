#include <string>
#include <iostream>

int main()
{
    std::string s = "Hello world";

    std::cout << sizeof(s) << std::endl;
    std::cout << s.size() << std::endl;

    return 0;
}