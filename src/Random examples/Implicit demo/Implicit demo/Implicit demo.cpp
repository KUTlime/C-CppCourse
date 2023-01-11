#include <iostream>
#include <vector>

class Foo
{
public:
	Foo(int x, int y)
	{
		x = x;
		y = y;
	};
	~Foo() {};

private:
	int x;
	int y;
};


int main()
{
	auto foo = new Foo(1, 1);
	Foo fooo = {1,1};
	std::vector<int> v = { 1, 2, 3, 4, 5 };
	char a[30] = { 'a'};
    std::cout << "Hello World!\n";
}