#include <vector>
using std::vector;
#include <algorithm>
using std::sort;
#include <ranges>

class Thing
{
private:
	int number;
	int limit;
public:
	Thing(int num, int lim) : number(num), limit(lim) {}
};

template <typename T>
	requires std::integral<T>
T add(T a, T b)
{
	return a + b;
}


int main()
{
	Thing t1{ 10,100 };
	Thing t2(3, 100);
	auto total = add(t1, t2);

	auto no = add(1, 2);


	vector<Thing> things;
	things.push_back(t1);
	things.push_back(t2);

		//sort(begin(things), end(things));
		//std::ranges::sort(things);

}