#include "Employee.h"
#include <string>
using std::string;

#include <vector>
using std::vector;
#include <algorithm>
using std::sort;

int main()
{
	Employee e1("Kate", 100);
	Employee e2("Kate", 200);
	Employee e3("Someone", 100);

	vector people{ e1,e2,e3 };
	sort(begin(people), end(people));
}

