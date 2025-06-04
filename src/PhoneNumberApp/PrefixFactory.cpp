#include "PrefixFactory.h"

PrefixFactory::PrefixFactory()
{
	validators.push_back(std::make_unique<UnitedKingdomValidator>());
	validators.push_back(std::make_unique<GermanyValidator>());
	validators.push_back(std::make_unique<CzechRepublicValidator>());
}

std::optional<InternationalPhonePrefix> PrefixFactory::Create(uint16_t prefix)
{
	for (auto& validator: validators)
	{
		if (validator->IsValid(prefix))
		{
			return validator->CreatePrefix();
		}
	}
    return std::optional<InternationalPhonePrefix>();
}
