#pragma once
#include <cstdint>
#include <iostream>

enum CountryCode
{
	Unknown = 0,
	UnitedKingdom = 44,
	Germany = 49,
	CzechRepublic = 420,
	Slovakia = 421
};

class InternationalPhonePrefix
{
private:
	uint16_t prefix = 0;
	CountryCode code = CountryCode::Unknown;
public:
	InternationalPhonePrefix(uint16_t prefix, CountryCode code);
	friend std::ostream& operator<< (std::ostream& out, const InternationalPhonePrefix& prefix);
	operator std::string() const;
};
