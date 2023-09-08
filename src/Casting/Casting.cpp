#include <iostream>

class A {};
class B : public A {};

void StaticCastDemo(const A & input)
{
    std::cout << typeid(input).name() << std::endl;
}

int main()
{
    B a = B();
    StaticCastDemo(a);
}