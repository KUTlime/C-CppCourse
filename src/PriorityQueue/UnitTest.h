#pragma once
#include <iostream>
#include <functional>
#include <string>
#include "PriorityQueue.h"

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
		auto pq = arrage();
		auto arragePq = act(pq);
		bool testResultIsSuccess = assert(arragePq);
		if (testResultIsSuccess)
		{
			std::cout << "The test '" << testName << "' was successfull." << std::endl;
			return;
		}
		std::cout << "The test '" << testName << "' failed." << std::endl;
	};
private:
	std::string testName;
	std::function<PriorityQueue()> arrage;
	std::function<PriorityQueue(PriorityQueue)> act;
	std::function<bool(PriorityQueue)> assert;
};

