#include <iostream>

void SomeRecursiveFunction(int i)
{
    std::cout << "Iteration " << i << std::endl;
    SomeRecursiveFunction(++i);
}

int main()
{
    int i = 1;
    SomeRecursiveFunction(i);
}