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



int main()
{
	int amount = 7;
	float price = 3.7;
	auto total = amount * price;
	string totalline = std::format("The total price for {} units at {} is {:.2f}.", amount, price, total);
	string difforder = std::format("It costs {2:.2f} for {0} units at {1}.", amount, price, total);

	Point p1(5, 7);
	string point = std::format("{}", p1);
}

