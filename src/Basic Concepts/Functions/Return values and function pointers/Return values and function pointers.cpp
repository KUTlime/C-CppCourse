#include <cstdio>
#include <iostream>
#include<string>

using namespace std;

int Func1()
{
	return 1;
}

int Func2(int i)
{
	return i * i; // What happens when * is a little bit big, hmm? 
}

string Func3()
{
	static string str = "This is a static string";
	return str;
}

// Declaration
const char* prompt(); // Prompt to user
int jump(const char*); // Do a jumt to function

// Functions for an array of the functions
void fa() { puts("this is fa()"); }
void fb() { puts("this is fb()"); }
void fc() { puts("this is fc()"); }
void fd() { puts("this is fd()"); }
void fe() { puts("this is fe()"); }

// Declaration on the function array
void(*funcs[])() = { fa, fb, fc, fd, fe, nullptr };


const char* prompt() {
	puts("Choose an option:");
	puts("1. Function fa()");
	puts("2. Function fb()");
	puts("3. Function fc()");
	puts("4. Function fd()");
	puts("5. Function fe()");
	puts("Q. Quit.");
	printf(">> ");

	fflush(stdout);                 // flush after prompt
	const int buffsz = 16;          // constant for buffer size
	static char response[buffsz];   // static storage for response buffer
	fgets(response, buffsz, stdin); // get response from console

	return response;
}

int jump(const char* rs) {
	char code = rs[0];
	if (code == 'q' || code == 'Q') return 0;

	// count the length of the funcs array
	int func_length = 0;
	while (funcs[func_length] != NULL) func_length++;

	int i = (int)code - '0';   // convert ASCII numeral to int
	i--;        // list is zero-based
	if (i < 0 || i >= func_length) {
		puts("invalid choice");
		return 1;
	}
	funcs[i](); // calling 
	return 1;
}

int main()
{
	string str = Func3();
	std::cout << str.c_str() << endl;

	while (jump(prompt()));
	puts("\nDone.");

	// return 0 is auto added here.
}

