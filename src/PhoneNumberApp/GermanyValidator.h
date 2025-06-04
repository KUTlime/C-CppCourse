#pragma once
#include "InternationalPhonePrefixValidatorBase.h"
class GermanyValidator :
    public InternationalPhonePrefixValidatorBase
{
public:
	GermanyValidator() : InternationalPhonePrefixValidatorBase(49, CountryCode::Germany)
	{
	}
};

