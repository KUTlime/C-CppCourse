#include <iostream>
import DoorStateMachine;

class GrandPa
{
public:
	GrandPa() { std::cout << "GrandPa ctor without parameter" << std::endl; };
	GrandPa(int a) { std::cout << "GrandPa ctor with parameter a " << a << std::endl; }
	~GrandPa() {};
	void MyOpinion() { std::cout << "I'm grand pa and you have to listen to me." << std::endl; }
};

class Mother : public GrandPa
{
public:
	Mother() { std::cout << "Mother ctor without parameters." << std::endl; };
	Mother(int a) { std::cout << "Mother ctor with parameter a" << a << std::endl; };
	~Mother() {};
};

class Father : public GrandPa
{
public:
	Father() { std::cout << "Father ctor without parameters." << std::endl; };
	Father(int a) : GrandPa(a) { std::cout << "Father ctor with parameter a" << a << std::endl; };
	~Father() {};
};


class Daughter : public Mother, protected Father
{
public:
	Daughter(int a) : Mother(a) { std::cout << "Daughter ctor with parameter a " << a << std::endl; };
	Daughter(int a, int b) { std::cout << "Daughter ctor with parameter a & b" << a << std::endl; };
	Daughter(int a, int b, int c) : Mother(a), Father(a) { std::cout << "Daughter ctor with parameter a & b & c" << a << std::endl; };
	~Daughter() {};
};

class Son : public Mother, public Father
{
public:
	Son(int a) : Mother(a) { std::cout << "Son ctor with parameter a " << a << std::endl; };
	Son(int a, int b) { std::cout << "Son ctor with parameter a & b" << a << std::endl; };
	Son(int a, int b, int c) : Mother(a), Father(a) { std::cout << "Son ctor with parameter a & b" << a << std::endl; };
	~Son() {};
	void MyOpinion() { std::cout << "I'm gen Z and I don't care." << std::endl; }
};

class NonBinaryChild : public Mother, public Father, public GrandPa
{
public:
	NonBinaryChild(int a) : Mother(a) { std::cout << "NonBinaryChild ctor with parameter a " << a << std::endl; };
	NonBinaryChild(int a, int b) { std::cout << "NonBinaryChild ctor with parameter a & b" << a << std::endl; };
	NonBinaryChild(int a, int b, int c) : Mother(a), Father(a), GrandPa(a) { std::cout << "NonBinaryChild ctor with parameter a & b" << a << std::endl; };
	NonBinaryChild(int a, int b, int c, int d) : Mother(a), Father(a)  { std::cout << "NonBinaryChild ctor with parameter a & b & c & d" << a << std::endl; };
	~NonBinaryChild() {};
	void MyOpinion() { std::cout << "I'm gen Z and I don't care." << std::endl; }
};

class Base {
public:
	void BaseSomething()
	{ }
};

class DerivedOne : public Base {
public:
	void DoSometingInOne()
	{ }
};

class DerivedTwo : public Base {
public:
	void DoSomethingInTwo()
	{ }
};

class WithProblem : public DerivedOne, public DerivedTwo {
public:
	void DoSomeProblem()
	{
		// BaseSomething();
	}
};

class WithoutProblem
{
private:
	DerivedOne one;
	DerivedTwo two;

public:
	void DoSomething()
	{
		one.BaseSomething();
		two.BaseSomething();
	}
};

class WithoutProblemVirtual : virtual public DerivedOne, virtual public DerivedTwo
{
	void DoSomething()
	{
		Base::BaseSomething();
	}
};

int main()
{
	std::cout << "1st Daughter" << std::endl;
	Daughter d(1);
	std::cout << "2nd Daughter" << std::endl;
	Daughter e(1, 2);
	std::cout << "3rd Daughter" << std::endl;
	Daughter f(1,2,3);
	std::cout << "1st Son" << std::endl;
	Son s(1);
	s.MyOpinion();
	std::cout << "1st NonBinaryChild" << std::endl;
	NonBinaryChild n(1, 2, 3, 4);

	DemoDoorStateMachine();
}