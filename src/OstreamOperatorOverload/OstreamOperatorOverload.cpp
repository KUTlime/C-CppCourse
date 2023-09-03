#include <iostream>

class PointWithNonMemberOverload {
public:
	PointWithNonMemberOverload(int x, int y) : x_(x), y_(y) {}

	int GetX() const { return x_; }
	int GetY() const { return y_; }

private:
	int x_;
	int y_;
};

std::ostream& operator<<(std::ostream& os, const PointWithNonMemberOverload& point) {
	os << "Point(" << point.GetX() << ", " << point.GetY() << ")";
	return os;
}

void NonMemberOverload()
{
	PointWithNonMemberOverload p(1, 2);
	std::cout << p << std::endl;
}

class PointWithMemberOverload {
public:
	PointWithMemberOverload(int x, int y) : x_(x), y_(y) {}

	int GetX() const { return x_; }
	int GetY() const { return y_; }

	friend std::ostream& operator<<(std::ostream& os, const PointWithMemberOverload& point) {
		os << "Point(" << point.x_ << ", " << point.y_ << ")";
		return os;
	}

private:
	int x_;
	int y_;
};

void MemberOverload()
{
	PointWithMemberOverload p(1, 2);
	std::cout << p << std::endl;
}

int main() {
	NonMemberOverload(); // Output Point(1,2)
	MemberOverload();    // Output Point(1,2)
}
