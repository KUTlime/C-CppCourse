#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
#include <format>
#include <functional>

void PrintName(std::string nameToPrint)
{
    std::cout << "Hello " << nameToPrint << std::endl;
}
void swap(int& x, int& y)
{
    auto t = x;
    x = y;
    y = t;
}

class Foo
{
private:
    int Value;
public:
    int publicValue;
    int getValue() { return Value; }
    void setValue(int value) { Value = value; }
};

class Point
{
public:
	Point(double x, double y): x(x), y(y) {}
    double x;
    double y;
};
class PointWithMemberOverload
{
private:
    double x;
    double y;
public:
    PointWithMemberOverload(double x, double y) : x(x), y(y) {}
    friend std::ostream& operator<< (std::ostream& out, const PointWithMemberOverload& point);
};
std::ostream& operator<<(std::ostream& out, const PointWithMemberOverload& point)
{
    out << "x: " << point.x << "y: " << point.y;
    return out;
}

std::ostream & operator<< (std::ostream& out, const Point& point)
{
    out << "x: " << point.x << "y: " << point.y;
    return out;
}
class PointWithConversion
{
private:
    double x;
    double y;
public:
    PointWithConversion(double x, double y) : x(x), y(y) {}
    operator std::string () const noexcept
    {
        return std::format("x: {}, y: {}", this->x, this->y);
    }
    operator Point () noexcept
    {
        Point p(this->x, this->y);
        return p;
    }
};
void function1()
{
    int a;
    int b;
    int c;
    int d;
    function2();
    try
    {
	    
    }
    catch (...)
    {
    }
}
void function2()
{
    int a;
    int b;
    int c;
    int d;
    throw std::invalid_argument("");

    // clearing of int d, c, b, a from scope 1
    // clearing of int d, c, b, a from scope 2
}

class SmartPointerToInteger
{
private:
    int * value = new int(0);
public:
    SmartPointerToInteger(int i) { *value = i; }
    ~SmartPointerToInteger() { delete value; value = nullptr; }
};

void DemoSmartPointerOfInterger()
{
    SmartPointerToInteger foo(42);
}

int main()
{
    std::vector<std::string> participans = {"Radek", "Olga", "David", "Tanner"};
    auto participan = participans[0];
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Hello " << participans[i] << std::endl;
    }
    for (auto p : participans)
    {
        //std::cout << "Hello " << p << " " << participan << std::endl;
    }
    //std::for_each(participans.begin(), participans.end(), PrintName);
    //std::for_each(participans.begin(), participans.end(), [](auto s) {std::cout << "Hello " << s << std::endl; });
    std::ranges::for_each(participans, PrintName);

    int x = 0;
    int y = 1;
    swap(x, y);

    Point p = { 1.0, 2.0 };
    PointWithMemberOverload op = { 1.0, 2.0 };
    PointWithConversion owc = { 1.0, 2.0 };

    std::cout << p;
    std::cout << op;
    std::cout << (std::string)owc;

    Point p2 = owc;
    p2(1.2, 2.2);

    try
    {
        throw std::exception();
    }
    catch (std::bad_alloc e)
    {
        e.what();
    }
    catch (...)
    {
        // std::exception will be catch here.
    }

    try
    {
        function1();
    }
    catch (...)
    {
        // eventually I will end up here.
    }

    auto labda = []() {return 42; };
	int i;
    std::cin >> i;
}
