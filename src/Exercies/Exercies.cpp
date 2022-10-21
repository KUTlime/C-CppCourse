#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>


void Exercice1()
{
	std::vector<std::vector<int>> jagger = { {1,2,3}, {-2, -14,55,53}, {0}, {-1, 2,-3,-4, -100} };
	int result = std::accumulate(jagger.begin(), jagger.end(), 0, []( int a, std::vector<int> v)
	{
			return a + std::accumulate(v.begin(), v.end(), 0);
	});
	std::cout << result << std::endl;
}
void Exercice2()
{
	std::vector<std::vector<int>> jagger = { {1,2,3}, {-2, -14,55,53}, {0}, {-1, 2,-3,-4, -100} };
	int result = 0;
	std::for_each(jagger.begin(), jagger.end(), [&result](std::vector<int>v)
	{
			std::for_each(v.begin(), v.end(), [&result](int i) {result += i;});
	});
	std::cout << result << std::endl;
}
void Exercice3()
{
	std::vector<std::vector<int>> jagger = { {1,2,3}, {-2, -14,55,53}, {0}, {-1, 2,-3,-4, -100} };
	int result =
	std::accumulate(jagger.begin(), jagger.end(), 0, [](int sum, std::vector<int> v)
	{
		return sum + std::reduce(v.begin(), v.end());
	});
	std::cout << result << std::endl;
}
void Exercice4()
{
	std::vector<std::vector<int>> jagger = { {1,2,3}, {-2, -14,55,53}, {0}, {-1, 2,-3,-4, -100} };
	int result = 0;
	std::ranges::for_each(jagger, [&result](std::vector<int> v)
	{
		std::ranges::for_each(v, [&result](int i) {result += i; });
	});
	std::cout << result << std::endl;
}


int main()
{
    Exercice1();
    Exercice2();
	Exercice3();
	Exercice4();
}