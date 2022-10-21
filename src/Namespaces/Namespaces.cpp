#include <iostream>
#include "TestClass.h"

void SomeFunction()
{
    using namespace Eaton;
    OutsideOfTheNamespace();
    Client();
    SPI();
    Microcontroller::SPI();
    Utilities::SomeUtility();
    SomeFunction2();
}
void SomeFunction2()
{
    OutsideOfTheNamespace();
    using namespace Eaton::Microcontroller;
    // Client(); // <- Not accesible here due to nesting in namespaces.
	SPI();
}

int main()
{
    OutsideOfTheNamespace outside();
    Eaton::Client client();
    Eaton::SPI spi();
    Eaton::Microcontroller::SPI();
    Eaton::Utilities::SomeUtility();

}