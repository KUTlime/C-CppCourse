#include "InternationalPhonePrefixValidator.h"
#include <unordered_set>

bool InternationalPhonePrefixValidator::IsValid(uint16_t prefix)
{
    static const std::unordered_set<uint16_t> validCodes =
    {
        Unknown,
        UnitedKingdom,
        Germany,
        CzechRepublic,
        Slovakia
    };
    return validCodes.contains(prefix);

    return false;
}

std::optional<InternationalPhonePrefix> InternationalPhonePrefixValidator::Validate(uint16_t prefix)
{
    if (IsValid(prefix))
    {
        return InternationalPhonePrefix(prefix, static_cast<CountryCode>(prefix));
    }
    return std::optional<InternationalPhonePrefix>();
}
