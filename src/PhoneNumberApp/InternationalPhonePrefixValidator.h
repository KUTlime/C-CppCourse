#pragma once
#include "InternationalPhonePrefix.h"
#include <optional>

class InternationalPhonePrefixValidator
{
private:
	bool IsValid(uint16_t prefix);
public:
	std::optional<InternationalPhonePrefix> Validate(uint16_t prefix);
};

