#pragma once
#include <optional>
#include "InternationalPhonePrefix.h"
#include "InternationalPhonePrefixValidatorBase.h"
#include "UnitedKingdomValidator.h"
#include "GermanyValidator.h"
#include "CzechRepublicValidator.h"
#include <vector>


class PrefixFactory
{
public:
	PrefixFactory();
	std::optional<InternationalPhonePrefix> Create(uint16_t prefix);
private:
	std::vector<std::unique_ptr<InternationalPhonePrefixValidatorBase>> validators;
};

