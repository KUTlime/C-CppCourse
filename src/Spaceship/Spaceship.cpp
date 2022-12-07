#include "Employee.h"
#include <string>
#include <iostream>
using std::string;

#include <vector>
using std::vector;
#include <algorithm>
using std::sort;

int main()
{
	Employee e1("Kate", 200);
	Employee e2("Kate", 100);
	Employee e3("Someone", 100);

	vector people{ e1,e2,e3 };
	sort(begin(people), end(people));
	for (auto person : people)
	{
		std::cout << person.GetName() << " " << person.GetNumber() << std::endl;
	};
}

