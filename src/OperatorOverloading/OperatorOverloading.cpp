#include <iostream>
#include <format>


class Point
{
public:
    Point(double x, double y) : x(x), y(y) {}
    double x;
    double y;
    Point operator+(const double& number)
    {
        return Point(x + number, y + number);
    }

    Point operator+(const Point& p) const
    {
        return Point(x + p.x, y + p.y);
    }

    Point operator()(double i)
    {
        return Point(i, i);
    }

    operator double()
    {
        return x + y;
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

std::ostream& operator<< (std::ostream& out, const Point& point)
{
    out << "(x: " << point.x << "y: " << point.y << ")";
    return out;
}

int main()
{
    Point p(0.0, 1.1);
    p = p + 1.2;
    p >> 2;
    p |= 2;
    p += 1.3;
    Point p1 = p(10.0);

    Point p2(0.0, 1.1);

    Point p3 = p2;

    double p4 = p3;

    // Overloading resolution got resolved here from point p3 to double. Why?
    // Conversion from Point to double has been declared first.
    std::cout << p3 << std::endl;

    std::cout << (std::string)p3 << std::endl;
}