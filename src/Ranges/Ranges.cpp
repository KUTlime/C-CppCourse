#include <vector>
using std::vector;
#include <algorithm>
using std::sort;
#include <ranges>
#include <iterator>
using std::back_inserter;
#include <iostream>
using std::cout;

struct PossibleValue { bool flag; int value; };


int main()
{
	vector numbers = { 1,26,7,10,21,32 };
	sort(begin(numbers), end(numbers));
	numbers.push_back(-1);
	numbers.push_back(-4);
	std::ranges::sort(numbers);

	vector<int> evens;
	copy_if(begin(numbers), end(numbers), back_inserter(evens), [](int n) { return n % 2 == 0; });

	vector<int> rEvens;
	std::ranges::copy_if(numbers, back_inserter(rEvens), [](int n) { return n % 2 == 0; });

	auto vEvens = numbers | std::views::filter([](int n) { return n % 2 == 0; });

	std::vector<PossibleValue> values = { {true, 1},{true,2},{false,3},{true, 4},{false, 5} };

	auto flagged = [](PossibleValue pv) {return pv.flag; };
	auto members = values
		| std::views::filter(flagged)
		| std::views::transform([](PossibleValue pv) { return pv.value; })
		| std::views::reverse
		| std::views::drop(2)
		;

	for (auto i : members)
	{
		cout << i << '\n';
	}



}
