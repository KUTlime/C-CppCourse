#pragma once
#include <string>

class Resource
{
private:
	std::string name;
public:
	Resource(std::string n);
	Resource(const Resource& r);
	Resource& operator=(const Resource& r);
	Resource(Resource&& r);
	Resource& operator=(Resource&& r);
	~Resource(void);
	bool operator>(const Resource& r) { return name > r.name; }
	bool operator<(const Resource& r) { return name < r.name; }
	bool operator==(const Resource& r) { return name == r.name; }
	std::string GetName() const { return name; }
};

