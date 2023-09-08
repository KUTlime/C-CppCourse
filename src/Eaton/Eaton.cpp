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
    Foo(const Foo& foo) 
    { 
        this->Value = foo.Value;
        this->publicValue = foo.publicValue;
    }
    int publicValue;
    int getValue() { return Value; }
    void setValue(int value) { Value = value; }
};

class Point
{
public:
	Point(double x, double y): x(x), y(y) {}
    Point(double n) : x(n), y(n) {}
    double x;
    double y;
    Point operator+(const double & number)
    {
        return Point(x + number, y + number);
    }

    Point operator+(const Point & p) const
    {
        return Point(x + p.x, y + p.y);
    }

    Point operator()(double i)
    {
        return Point(i, i);
    }

    operator double()
    {
        return x+y;
    }

    operator std::string()
    {
        return std::format("x: {}, y: {}", x, y);
    }

    Point& operator+=(double number)
    {
        x += number;
        y += number;
        return *this;
    }

    Point& operator>>(const double& number)
    {
        x += number;
        y += number;
        return *this;
    }

    Point& operator|=(const double& number)
    {
        x += number;
        y += number;
        return *this;
    }
};
/*
std::ostream& operator<< (std::ostream& out, const Point& point)
{
    out << "x: " << point.x << "y: " << point.y;
    return out;
}*/

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

void HowToCreateString()
{
    using std::string;
    // stack allocated
    string s1();
    string s2{};
    string s3("asdf");
    string s4{ "asdf" };
    string s5 = "asdf";
    string s6 = { "asdf" };
    string s7 = { 'a', 's', 'd', 'f' };
    // heap allocated
    string* s8 = new string("asdf");
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

    Point p(0.0, 1.1);
    p = p + 1.2;
    p >> 2;
    p |= 2;
    p += 1.3;
    Point p1 = p(10.0);

    Point p2(0.0, 1.1);

    auto p3 = p + p2;

    double p4 = p3;

    std::cout << p3 << std::endl;
}
