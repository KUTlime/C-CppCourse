#pragma once
#include "ICommand.h"
class Queue
{
public:
	virtual void enqueu(ICommand) = 0;
	virtual ICommand dequeu() = 0;
};

class PriorityQueue : public Queue
{
public:
	virtual int getNumberCommandsInQueue() { return 1; }
	virtual void enqueu(ICommand) {};
	virtual ICommand dequeu() 
	{
		ICommand emptyValue;
		return emptyValue;
	};
};

void QueueShouldEnqueuTheCommand();
