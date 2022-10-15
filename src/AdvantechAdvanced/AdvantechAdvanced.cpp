#include <iostream>
#include "DebugClass.h"
#include <string>
#include <vector>
#include <functional>

using namespace std::literals::string_literals;

using namespace Advantech;
using namespace Utilities;

void CreateMemoryLeak(int rounds)
{
    for (size_t i = 0; i < rounds; i++)
    {
        auto dg = new MemoryLeak(i, i);
    }
}

int GetIntNumberFromUser(const std::string& prompt, uint64_t numberOfAttempt = UINT64_MAX)
{
    std::string valueFromUser;
    uint64_t attempt = 0;
    while(attempt < numberOfAttempt)
    { 
        std::cout << (attempt == 0 ? prompt : "Please repeat the entry.");
        std::getline(std::cin, valueFromUser);
        try
        {
            return std::stoi(valueFromUser);
        }
        catch (const std::invalid_argument & e)
        {
            std::cout << "You have entered an invalid integer value." << std::endl;
        }
        attempt++;
    }
    throw std::invalid_argument("The attemps has been depleted.");
}

void ExecuteTest(std::string testName, uint64_t numberOfAttempts, bool expectingException = false)
{
    std::cout << "Starting test " << testName << std::endl;
    if (expectingException)
    {
        try
        {
            GetIntNumberFromUser("Entry a valid value ", numberOfAttempts);
        }
        catch (const std::exception& e)
        {
            std::cout << e.what() << std::endl;
            std::cout << "Test completed" << std::endl;
        }
    }
    else
    {
        int testValue = GetIntNumberFromUser("Entry a valid value ", numberOfAttempts);
        std::cout << "Test result: " << testValue << std::endl;
    }
    
}

void MakeSomethingDangerous()
{
    int a;
    std::cout << "Enter a value: " << std::endl;
    std::cin >> a;
    throw std::invalid_argument("Something went wrong...");
}

void DemoSmartPointer()
{
    NotSoSmartPointer ptr(13);
    throw std::bad_alloc();
}

std::function<int(int)> GenerateLambda(int i)
{
    switch (i)
    {
        case 1:
            return [i](int multiplier) {return i * multiplier; };
        case 2:
            return [](int multiplier) {return multiplier + multiplier; };
        default:
            return [](int multiplier) {return 0; };
    }   
}

void GenerateLambdaScope()
{
    int i = 2;
    auto test = GenerateLambda(2);

    // Replace by lambda
    auto test2 = [i](int multiplier) {
        return [i](int multiplier) {return i * multiplier; };
    };
    auto test3 = test2(i);
}

class MyClass
{
public:
    virtual int GetSomeNumber() = 0;
};

class MyClass2ndGeneration : public MyClass
{};

int main()
{
    MyClass mc();
    MyClass2ndGeneration mc2g();

    DebugClass dg1();
    DebugClass dg2(2);
    DebugClass dg3 = dg2;
    DebugClass dg4 = 4;
    DebugClass dg5{5};
    std::cout << "i value is " << dg2.GetIValue() << std::endl;
    std::cout << "i value from dg4 is " << dg4.GetIValue() << std::endl;
    std::string test{'a', 'b', 'c'};
    std::cout << test << std::endl;

    std::cout << dg5 << std::endl;

    std::cout << std::to_string(1) << std::endl;

    DebugClass dg6(6);

    std::cout << std::string(dg6) << std::endl;

    std::vector<DebugClass> v = dg6;

    auto dg7 = new DebugClass(7);

    if (dg6)
    {
        std::cout << "Yeah, we can have a bool from anything :))" << std::endl;
    }
    //CreateMemoryLeak(100000);

    InAdvantechNamespace test1();

    Product::SomeProduct test2();

    Firmaware firmaware();
    try
    {
        DemoSmartPointer();
    }
    catch (const std::bad_alloc& e)
    {
        std::cout << "Lets see what we have in console." << std::endl;
    }

    ExecuteTest("Zero attempts", 0);
    ExecuteTest("A single attempt happy path", 1);
    ExecuteTest("A single attempt unhappy path", 1, true);
    ExecuteTest("Two attempts invalid + happy path", 2);
    ExecuteTest("Two attempts invalid + unhappy path", 2, true);


    try
    {
        MakeSomethingDangerous();
    }
    catch (...)
    {
        std::exception_ptr p = std::current_exception();
        std::cout << "Something really, really bad happened." << std::endl;
    }

    auto test3 = [](){};
}

