#include <iostream>
#include <vector>

class Point
{
public:
	Point(int x, int y) : x(x), y(y) {};
	~Point() {};
	int GetX() const { return x; };
	int GetY() const { return y; };

private:
	int x;
	int y;
};
std::ostream& operator<< (std::ostream& out, const Point& point)
{
	out << "X: " << point.GetX() << " Y: " << point.GetY();
	return out;
}

int main()
{
	Point p(10, 1);
	Point p2 = { 1, 2 };
	std::vector<int> v = { 1, 2, 3 };
	std::cout << p << std::endl;
    std::cout << "Hello World!\n";
}