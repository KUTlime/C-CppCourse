#pragma once
#include <string>
class ICommand
{
	virtual std::string getPayload() { return ""; };
};

