#include "Resource.h"
#include <iostream>

#include <chrono>
using std::chrono::system_clock;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::milliseconds;

#include <string>
using std::string;

#include <vector>
#include <list>
using std::vector;
using std::list;

#include <algorithm>

template <typename Func>
long long TimeFunc(Func f)
{
	auto begin = steady_clock::now();
	f();
	auto end = steady_clock::now();

	return duration_cast<milliseconds>(end - begin).count();
}


template <typename T>
void exercise(int size, string commonname)
{
	T v;
	T::template value_type res1("starting entry");
	v.push_back(res1);
	for (int i = 0; i < size; i++)
	{
		int r = (int)rand();
		string s;
		int ss = r % 100;
		s.reserve(ss);
		std::generate_n(std::insert_iterator(s, s.end()), ss, [ss]() {return (char)('!' + ss / 2); });
		T::template value_type res(s);
		bool inserted = false;
		for (auto it = begin(v); it != end(v); it++)
		{
			if (*it > res)
			{
				v.insert(it, res);
				inserted = true;
				break;
			}
		}
		if (!inserted)
			v.push_back(res);
	}

	auto it = max_element(begin(v), end(v));
	T::template value_type maxV = *it;
	it = min_element(begin(v), end(v));
	T::template value_type minV = *it;

	bool sorted = is_sorted(begin(v), end(v));
}


int main()
{
	const int size = 1000;

	auto vectormilliseconds = TimeFunc([&]() {exercise<vector<Resource>>(size, "vector"); });
	auto listmilliseconds = TimeFunc([&]() {exercise<list<Resource>>(size, "list"); });

	std::cout << "Vector miliseconds: " << vectormilliseconds << std::endl;
	std::cout << "List miliseconds: " << listmilliseconds << std::endl;

}
