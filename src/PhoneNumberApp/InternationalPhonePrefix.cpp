#include "InternationalPhonePrefix.h"
#include <iostream>
#include <string>

InternationalPhonePrefix::InternationalPhonePrefix(uint16_t prefix, CountryCode code) : prefix(prefix), code(code)
{
}

std::ostream& operator<<(std::ostream& out, const InternationalPhonePrefix& prefix)
{
	out << "Prefix: +" << prefix.code << std::endl;
	return out;
}

InternationalPhonePrefix::operator std::string() const
{
	return "+" + std::to_string(code);
}
