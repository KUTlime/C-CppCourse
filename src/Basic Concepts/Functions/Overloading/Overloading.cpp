#include <cstdio>
#include <cstdarg>
using namespace std;

// volume of a cube
double volume(double a)
{
	printf("cube of %.3lf\n", a);
	return a * a * a;
}

// volume of a cylinder
double volume(double r, double h)
{
	const static double _pi = 3.141592653589793;
	printf("cylinder of %.3lf x %.3lf\n", r, h);
	return _pi * r * r * h;
}

// volume of a cuboid
double volume(double a, double b, double c) {
	printf("cuboid of %.3lf x %.3lf x %.3lf\n", a, b, c);
	return a * b * c;
}

// Overloading of operators by function
class SimpleClass
{
	int _a;
public:
	// Constructor
	SimpleClass(const int& a) : _a(a)
	{
	}

	// public method for returning value
	const int& value() const
	{
		return _a;
	}
}; // Look here, this is a statement!

// A function which overloading + operator with two operand of class A
int operator + (const SimpleClass& lhs, const SimpleClass& rhs)
{
	puts("operator + for class A");
	return lhs.value() + rhs.value();
}

int operator ++ (const SimpleClass& lhs)
{
	puts("operator ++ for class A");
	return lhs.value() + 1;
}


// first argument is int count of remaining args
// ... remaining args are doubles for average
double average(const int count, ...)
{
	va_list ap; // list of arguments
	double total = 0.0;

	va_start(ap, count);
	for (int i = 0; i < count; ++i) {
		total += va_arg(ap, double);
	}
	va_end(ap);
	return total / count;
}

// works like printf, format plus args
int message(const char* fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	int rc = vfprintf(stdout, fmt, ap); // printf with variable argument number
	puts("");
	va_end(ap);
	return rc;
}



int main(int argc, char** argv)
{
	printf("volume of a 2 x 2 x 2 cube: %.3lf\n", volume(2.0));
	printf("volume of a cylinder, radius 2, height 2: %.3lf\n", volume(2.0, 2.0));
	printf("volume of a 2 x 3 x 4 cuboid: %.3lf\n", volume(2.0, 3.0, 4.0));


	SimpleClass a(7);
	SimpleClass b(42);
	printf("add em up! %d\n", a + b);
	printf("prefix operator ++%d = %d\n", a, ++a);


	message("This is a message");
	message("Average: %lf", average(5, 25.0, 35.7, 50.1, 127.6, 75.0, 41.5));

	return 0;
}
