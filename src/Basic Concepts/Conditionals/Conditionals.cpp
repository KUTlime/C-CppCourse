#include <iostream>

int main()
{
    int a = 0;

    // Do something extra
    if (a == 0)
    {
        std::cout << "a has not been initialized to non zero value.\n";
    }

    if (a == 0)
    {
        std::cout << "a has not been initialized to non zero value.\n";
    }
    else
    {
        std::cout << "a has been initialized to non zero value.\n";
    }

    if (a == 0)
    {
        std::cout << "a has not been initialized to non zero value.\n";
    }
    else if (a == 1)
    {
        std::cout << "a has been initialized to 1 value.\n";
    }
    else
    {
        std::cout << "a has been initialized to some value.\n";
    }
    
    switch (a)
    {
    case 0:
        std::cout << "Zero\n";
        break; // Stop executing the switch
    case 1:
        std::cout << "One\n";
        break; // Stop executing the switch
    default:
        break;
    }

}