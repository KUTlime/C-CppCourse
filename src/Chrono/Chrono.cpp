#include <chrono>
#include <iostream>
using namespace std::chrono_literals;
using std::cout;


int main()
{
	auto now = std::chrono::system_clock::now();
	cout << "time: " << now << '\n';
	auto nowlocal = std::chrono::zoned_time{ std::chrono::current_zone(), now};
	cout << "local time: " << nowlocal << '\n';
	cout << std::chrono::current_zone() << std::endl;

	auto date1 = 1d / std::chrono::February / 2025;
	date1 += std::chrono::months(1);
	auto datepoint1 = std::chrono::sys_days(date1);
	auto date2 = 15d / std::chrono::October / 2025;
	auto datepoint2 = std::chrono::sys_days(date2);

	auto diff = datepoint2 - datepoint1;
	diff += std::chrono::days(2);

}
