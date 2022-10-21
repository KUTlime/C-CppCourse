#pragma once

namespace Eaton
{
	class Client{};

	namespace Utilities
	{
		class SomeUtility{};
	}

	inline namespace Microcontroller
	{
		class SPI{};
	}
}
class OutsideOfTheNamespace{};

class TestClass
{
private:
	int i;
public:
	void SayHello(int);
};

