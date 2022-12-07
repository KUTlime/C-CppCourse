#include <iostream>
class S {
public:
	int static_value() {
		static int x = 7;
		return ++x;
	}
};

int func() {
	int x = 7;
	return ++x;
}

int func2() {
	static int x = 7;
	return ++x;
}

int main(int argc, char** argv) {
	int i = 42;
	// const int i = 42;
	i = 1;

	printf("The integer is %d\n", func());
	printf("The integer is %d\n", func());
	printf("The integer is %d\n", func());
	printf("The integer is %d\n", func());

	printf("The integer is %d\n", func2());
	printf("The integer is %d\n", func2());
	printf("The integer is %d\n", func2());
	printf("The integer is %d\n", func2());

	S a;
	S b;

	printf("The integer is %d\n", a.static_value());
	printf("The integer is %d\n", b.static_value());

	return 0;
}
