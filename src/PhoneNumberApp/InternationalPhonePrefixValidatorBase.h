#pragma once
#include "InternationalPhonePrefix.h"
#include <optional>

class InternationalPhonePrefixValidatorBase
{
public:
	InternationalPhonePrefixValidatorBase(uint16_t prefix, CountryCode code) : code(code), prefix(prefix)
	{
	}
	virtual bool IsValid(uint16_t prefix);
	virtual std::optional<InternationalPhonePrefix> CreatePrefix();

protected:
	CountryCode code;
	uint16_t prefix;
};

