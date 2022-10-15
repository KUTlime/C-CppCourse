#include "DebugClass.h"
#include <iostream>

namespace Advantech::Utilities
{
	DebugClass::DebugClass()
	{
		std::cout << "DebugClass Empty constructor" << std::endl;
		this->i = 0;
	}

	DebugClass::DebugClass(int i) : DebugClass()
	{
		std::cout << "DebugClass constructor with value " << i << std::endl;
		this->i = i;
	}

	DebugClass::DebugClass(const DebugClass& debugClass) : i(debugClass.i)
	{
		std::cout << "DebugClass copy constructor" << std::endl;
	}

	DebugClass::DebugClass(const DebugClass&& debugClass)
	{
		std::cout << "DebugClass move constructor" << std::endl;
	}

	DebugClass& DebugClass::operator=(const DebugClass& t)
	{
		std::cout << "DebugClass Copy assignment operator" << std::endl;
		this->i = t.i;
		return *this;
	}

	DebugClass& DebugClass::operator=(DebugClass&& t) noexcept
	{
		std::cout << "DebugClass Move assignment operator" << std::endl;
		this->i = t.i;
		return *this;
	}

	DebugClass::operator std::string() const
	{
		return std::string("DebugClass " + std::to_string(i));
	}

	DebugClass::operator std::vector<DebugClass>() const
	{
		return {*this};
	}

	DebugClass::operator bool() const
	{
		return i % 2 == 0;
	}

	int DebugClass::GetIValue() const
	{
		return i;
	}

	void DebugClass::SetIValue(int i)
	{
		this->i = i;
	}

	DebugClass::~DebugClass()
	{
		std::cout << "DebugClass destructor instance i " << i << std::endl;
	}
	//std::ostream& operator<<(std::ostream& out, const Advantech::Utilities::DebugClass& debugClass)
	//{
	//	std::cout << debugClass.i;
	//	return out;
	//}

	NotSoSmartPointer::NotSoSmartPointer(int i) : pointerToReference(new DebugClass(i)) {};
	NotSoSmartPointer::~NotSoSmartPointer() {
		delete pointerToReference;
	};
}

std::ostream& operator<<(std::ostream& out, Advantech::Utilities::DebugClass& debugClass)
{
	debugClass.SetIValue(10);
	out << debugClass.GetIValue();
	return out;
}


