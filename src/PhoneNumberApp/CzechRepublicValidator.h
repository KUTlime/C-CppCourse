#pragma once
#include "InternationalPhonePrefixValidatorBase.h"

class CzechRepublicValidator :
    public InternationalPhonePrefixValidatorBase
{
public:
	CzechRepublicValidator() : InternationalPhonePrefixValidatorBase(420, CountryCode::CzechRepublic)
	{

	}
};

