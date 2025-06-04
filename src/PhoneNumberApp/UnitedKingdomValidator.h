#pragma once
#include "InternationalPhonePrefixValidatorBase.h"
class UnitedKingdomValidator :
    public InternationalPhonePrefixValidatorBase
{
public:
	UnitedKingdomValidator() : InternationalPhonePrefixValidatorBase(44, CountryCode::UnitedKingdom)
	{
	}
};

