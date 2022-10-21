#pragma once
#include <string>

class ICommand
{
private:
	std::string payload;
	std::uint8_t priority;
public:
	ICommand(std::string str, uint8_t priority) : payload(str), priority(priority){}
	ICommand() : payload(""), priority(0){}
	virtual std::string getPayload() const { return payload; };
	virtual uint8_t getPriority() const noexcept { return priority; };
};

