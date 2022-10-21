#pragma once
#include <queue>
#include <execution>
#include <numeric>
#include <map>
#include "ICommand.h"

class Queue
{
public:
	virtual void enqueu(ICommand) = 0;
	virtual ICommand dequeu() = 0;
};

class LowPriorityCommand : public ICommand
{
public:
	virtual std::string getPayload() const override { return ""; };
	virtual uint8_t getPriority() const noexcept override { return 100; };
};

class PriorityQueue : public Queue
{
public:
	virtual size_t getNumberCommandsInQueue() 
	{ 
		size_t sum = 0;
		for (auto& [key, queue] : priorityQueue)
		{
			sum += queue.size();
		};
		return sum;
	//std::ranges::for_each(priorityQueue, [&sum](std::pair<uint8_t, std::queue<ICommand>> pair) {return sum + pair.second.size(); });
	}
	virtual void enqueu(ICommand command)
	{
		if (priorityQueue.contains(command.getPriority()))
		{
			auto& queue = priorityQueue.at(command.getPriority());
			queue.push(command);
			return;
		}
		std::queue<ICommand> queue;
		queue.push(command);
		priorityQueue.insert({ command.getPriority(), queue });
	}
	virtual ICommand dequeu() 
	{
		if (priorityQueue.empty())
		{
			ICommand null("", 0);
		}
		auto& lastKey = std::prev(priorityQueue.end())->first;
		auto& queueForLastKey = priorityQueue.at(lastKey);
		auto& theHighestPriorityCommand = queueForLastKey.front();
		return theHighestPriorityCommand;
	};
private:
	std::map<uint8_t, std::queue<ICommand>> priorityQueue;
};
