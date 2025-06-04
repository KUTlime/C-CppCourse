#include "InternationalPhonePrefixValidatorBase.h"


bool InternationalPhonePrefixValidatorBase::IsValid(uint16_t prefix)
{
	return prefix == this->prefix;
}

std::optional<InternationalPhonePrefix> InternationalPhonePrefixValidatorBase::CreatePrefix()
{
	return InternationalPhonePrefix(prefix, code);
}


