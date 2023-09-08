#include <iostream>

void HowMutableWorks()
{
    std::cout << "How capture by value and mutable works:" << std::endl;
    int n = 19;
    // [=]() {n = 10; }(); // won't work without mutable
    auto f1 = [=]() mutable
    {
        std::cout << "n (from inside lambda scope): " << n << std::endl;
        n = 20;
        std::cout << "n (from inside lambda scope): " << n << std::endl;
    };
    f1();
    std::cout << "n (from outside lambda scope): " << n << std::endl;
    f1();
}

void HowCaptureReferenceWorks()
{
    std::cout << "How capture by reference works:" << std::endl;
    int n;
    auto f1 = [&]()
        {
            std::cout << "n (from inside lambda scope): " << n << std::endl;
            n = 20;
            std::cout << "n (from inside lambda scope): " << n << std::endl;
        };
    f1();
    std::cout << "n (from outside lambda scope): " << n << std::endl;
    f1();
}

void ConstantValueWithoutExtraMemoryAllocation()
{
    std::cout << "Capture a value that remains constant and no memory allocation" << std::endl;
    int n = 0;
    std::cout << &n << std::endl;
    [&n = std::as_const(n)]() {/*n = 10*/std::cout << &n << std::endl; }();
    [&n]() {n = 10; std::cout << &n << std::endl; }();
    std::cout << &n << std::endl;
}

int main()
{
    HowMutableWorks();
    HowCaptureReferenceWorks();
    ConstantValueWithoutExtraMemoryAllocation();
}