
#include <iostream>
using std::cout;
#include <vector>
using std::vector;

#include "generator.hpp"   // from https://github.com/TartanLlama/generator 

tl::generator<int> produce_nums()
{
	int i = -1; // will increment to produce first number
	while (true)
	{
		i++;
		cout << "generated " << i << '\n';
		co_yield i;
	}
}

void print_nums(int const n)
{
	int count = 1;
	for (auto const& num : produce_nums())
	{
		cout << "consumed " << num << '\n';
		std::cout << num << '\n';
		if (++count > n) break;
	}

	return;
}

vector<int> getNums()
{
	return vector<int>{ 0, 1, 2, 3 };
}

void printNums(vector<int> n)
{
	for (auto i : n)
	{
		cout << i << '\n';
	}
}

int main()
{
	vector<int> nums = getNums();
	printNums(nums);
	cout << '\n';

	for (int i = 0; i < 4; ++i)
	{
		cout << i << '\n';
	}
	cout << '\n';

	print_nums(4);
}

