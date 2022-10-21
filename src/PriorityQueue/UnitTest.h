#pragma once
#include <iostream>
#include <functional>
#include <string>
#include "PriorityQueue.h"

#include <ostream>
namespace Color {
	enum Code {
		FG_RED = 31,
		FG_GREEN = 32,
		FG_BLUE = 34,
		FG_DEFAULT = 39,
		BG_RED = 41,
		BG_GREEN = 42,
		BG_BLUE = 44,
		BG_DEFAULT = 49
	};
	class Modifier {
		Code code;
	public:
		Modifier(Code pCode) : code(pCode) {}
		friend std::ostream&
			operator<<(std::ostream& os, const Modifier& mod) {
			return os << "\033[" << mod.code << "m";
		}
	};
}

class PriorityQueueUnitTest
{
public:
	PriorityQueueUnitTest(
		std::string testName,
		std::function<PriorityQueue()> arrage,
		std::function<PriorityQueue(PriorityQueue)> act,
		std::function<bool(PriorityQueue)> assert
	)
		:
		testName(testName),
		arrage(arrage),
		act(act),
		assert(assert)
	{}
	void ExecuteTest() 
	{
		Color::Modifier green(Color::FG_GREEN);
		Color::Modifier red(Color::FG_RED);
		Color::Modifier def(Color::FG_DEFAULT);
		auto pq = arrage();
		auto arragePq = act(pq);
		bool testResultIsSuccess = assert(arragePq);
		if (testResultIsSuccess)
		{
			std::cout << green << "The test '" << testName << "' was successfull." << def << std::endl;
			return;
		}
		
		std::cout << red << "The test '" << testName << "' failed." << def << std::endl;
	};
private:
	std::string testName;
	std::function<PriorityQueue()> arrage;
	std::function<PriorityQueue(PriorityQueue)> act;
	std::function<bool(PriorityQueue)> assert;
};

