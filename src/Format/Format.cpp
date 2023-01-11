#include <iostream>
#include <format>
#include <string>
using std::string;

class Point
{
public:
	int x;
	int y;
	Point(int x, int y) : x(x), y(y) {}
};
template <>
struct std::formatter<Point> : std::formatter<std::string> {
	auto format(Point p, format_context& ctx) {
		return formatter<string>::format(
			std::format("({}, {})", p.x, p.y), ctx);
	}
};

// Old-school alternative
class PointV2
{
public:
	int x;
	int y;
	PointV2(int x, int y) : x(x), y(y) {};
	string GetString() const
	{ 
		char str[25];
		sprintf_s(str, "(%d, %d)", x, y);
		string s = str;
		return s;
	};
	operator string () const { return GetString(); };
};

// No so old school implementation
class PointV3
{
public:
	int x;
	int y;
	PointV3(int x, int y) : x(x), y(y) {};
	string GetString() const
	{
		return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
	};
	operator string () const { return GetString(); };
};


int main()
{
	int amount = 7;
	float price = 3.7;
	auto total = amount * price;
	string totalline = std::format("The total price for {} units at {} is {:.2f}.", amount, price, total);
	string difforder = std::format("It costs {2:.2f} for {0} units at {1}.", amount, price, total);

	Point p1(5, 7);
	string point = std::format("{}", p1); // vs.
	string point2 = std::format("({}, {})", p1.x, p1.y);

	std::cout << totalline << std::endl;
	std::cout << difforder << std::endl;
	std::cout << point << std::endl;

	PointV2 p2(10, 11111111);
	std::cout << p2.GetString() << std::endl;

	PointV2 p3(11111111, 10);
	string p3s = p3;
	std::cout << p3s << std::endl;

	string semiFormattedString = "(" + std::to_string(p1.x) + ", " + std::to_string(p1.y) + ")";
	std::cout << semiFormattedString << std::endl;

	PointV3 p4(4444, 5555);
	std::cout << (string)p4 << std::endl;
}

