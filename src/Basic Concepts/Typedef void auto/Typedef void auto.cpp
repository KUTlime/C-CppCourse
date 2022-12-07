#include <cstdio>
#include <string>
#include <typeinfo>
#include <vector>
using namespace std;

// Typedef demo
typedef unsigned char points_t;
typedef unsigned char rank_t;

struct Score
{
	points_t points;
	rank_t rank;
};

void Typedef_demo()
{
	Score s = { 5,1 };
	printf("score s has %d points and rank of %d\n", s.points, s.rank);
}


// Void demo
void func(void)
{
	puts("this is void func ( void )");
}


// Auto definition demo
auto String_function()
{
	return string("this is a string");
}

void Auto_demo(void)
{
	auto x = String_function();
	printf("x is %s\n", x.c_str());
	printf("type of x is %s\n", typeid(x).name());


	vector<int> numbers = { 1,2,3,4,5 };

	for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
	{
		printf("int is %d\n", *it);
	}

	// No.1 improvement by auto
	for (auto it = numbers.begin(); it != numbers.end(); ++it)
	{
		printf("int is %d\n", *it);
	}

	// No.2 improvement by auto
	for (auto i : numbers)
	{
		printf("int is %d\n", i);
	}

}

// Null pointer ambiguous pointer call
#ifndef NULL
#define NULL (0LL) /* common C++ definition */
#endif

void f(int i) {
	printf("the int is %d\n", i);
}

void f(const char* s) {
	printf("the pointer is %p\n", s);
}

void Null_demo()
{
	f(NULL);
}

int main(int argc, char** argv)
{
	Typedef_demo();

	puts("calling func()");
	func();

	Auto_demo();

	return 0;
}
