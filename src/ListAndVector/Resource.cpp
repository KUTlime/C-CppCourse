#include "Resource.h"
#include <iostream>
using std::cout;
using std::string;

Resource::Resource(string n) :name(n)
{
	//	cout << "constructing " << name << '\n';
}

Resource::Resource(const Resource& r) : name(r.name)
{
	//	cout << "copy constructing " << name << '\n';
}

Resource& Resource::operator=(const Resource& r)
{
	//if class contained true Resources, clean up existing ones
	//before setting new values
	name = r.GetName();
	//	cout << "copy assigning " << name << '\n';
	return *this;
}

Resource::Resource(Resource&& r) :name(std::move(r.name))
{
}

Resource& Resource::operator=(Resource&& r)
{
	if (this != &r)
	{
		name = std::move(r.name);
		r.name.clear();
		//	cout << "move assigning " << name << '\n';
	}
	return *this;
}

Resource::~Resource(void)
{
	//	cout << "destructing " << name << '\n';
}
