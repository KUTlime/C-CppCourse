#pragma once
#include <string>
using std::string;
class Employee
{
private:
	int number;
	string name;
public:
	auto operator <=>(const Employee& other) const = default;
	Employee(string fullname, int arbitrarynumber) : name(fullname), number(arbitrarynumber) {}
};

