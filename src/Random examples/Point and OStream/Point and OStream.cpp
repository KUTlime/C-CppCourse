#include <iostream>
#include <vector>

class Point
{
public:
	Point(int x, int y) : x(x), y(y) {};
	~Point() {};
	int GetX() const { return x; };
	int GetY() const { return y; };
	operator std::string() const 
	{
		return "asdfasdfasdf";
	}

private:
	int x;
	int y;
};
std::ostream& operator<< (std::ostream& out, const Point& point)
{
	out << "X: " << point.GetX() << " Y: " << point.GetY();
	return out;
}

class PointWithMemberFunction
{
public:
	PointWithMemberFunction(int x, int y) : x(x), y(y) {};
	~PointWithMemberFunction() {};
	int GetX() const { return x; };
	int GetY() const { return y; };
	friend std::ostream& operator<< (std::ostream& out, const Point& point)
	{
		out << "X: " << this->x << " Y: " << this->y;
		return out;
	};

private:
	int x;
	int y;
};

class PointWithStringCasting
{
public:
	PointWithStringCasting(int x, int y) : x(x), y(y) {};
	~PointWithStringCasting() {};
	int GetX() const { return x; };
	int GetY() const { return y; };
	operator std::string() const { return "asdfasdfasdf"; }
	operator Point() const { return Point(x, y); }

private:
	int x;
	int y;
};

int main()
{
	Point p(10, 1);
	Point p2 = { 1, 2 };
	std::vector<int> v = { 1, 2, 3 };
	std::cout << p << std::endl;
	PointWithMemberFunction p3(10, 1);
	/*std::cout << p3 << std::endl;*/
	PointWithStringCasting p4(10, 1);
	std::cout << (std::string)p4 << std::endl;
    std::cout << "Hello World!\n";
}