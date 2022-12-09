#include <iostream>
#include <string>

enum Scale
{
    Unknown,
    Celcius,
    Fahrenheit,
    Kelvin
};

struct Temperature
{
    Scale scale;
    double value;
};

double GetDoubleFromUser()
{
    double result;
    std::string str;
    std::cout << "Please, specify the temperature value: " << std::endl;
    std::getline(std::cin, str);
    result = std::stod(str);
    return result;
}

Scale GetScaleFromUser()
{
    std::string str;
    std::cout << "Please, specify input scale ['C', 'F', 'K']: " << std::endl;
    std::getline(std::cin, str);
    if (str[0] == 'C')
    {
        return Celcius;
    }
    if (str[0] == 'F')
    {
        return Fahrenheit;
    }
    if (str[0] == 'K')
    {
        return Kelvin;
    }
    return Unknown;
}

Temperature GetTemperatureFromUser()
{
    Temperature temp;
    temp.scale = GetScaleFromUser();
    temp.value = GetDoubleFromUser();
    return temp;
}

std::string GetScaleAsString(Scale scale)
{
    switch (scale)
    {
    case 1:
        return "Celcius";
    case 2:
        return "Fahrenheit";
    case 3:
        return "Kelvin";
    default:
        return "Unknown scale";
    }
}

Temperature* GetCalculatedTemperature(Temperature temperature)
{
    Temperature temperatures[3];
    Temperature temp1;
    Temperature temp2;
    if (temperature.scale == Celcius)
    {
        temperatures[0] = temperature;
        temp1.scale = Fahrenheit;
        temp1.value = temperature.value * 9 / 5 + 32;
        temperatures[1] = temp1;
        temp2.scale = Kelvin;
        temp2.value = temperature.value + 273.15;
        temperatures[2] = temp2;
    }
    if (temperature.scale == Fahrenheit)
    {
        temperatures[1] = temperature;
        temp1.scale = Celcius;
        temp1.value = (temperature.value - 32) * 5 / 9;
        temperatures[0] = temp1;
        temp2.scale = Kelvin;
        temp2.value = temp1.value + 273.15;
        temperatures[2] = temp2;
    }
    if (temperature.scale == Kelvin)
    {
        temperatures[2] = temperature;
        temp1.scale = Celcius;
        temp1.value = temperature.value - 273.15;
        temperatures[0] = temp1;
        temp2.scale = Fahrenheit;
        temp2.value = temp1.value * 9 / 5 + 32;
        temperatures[1] = temp2;
    }
    return temperatures;
}

void PrintTemperature(Temperature temp)
{
    std::cout << temp.value << (temp.scale == Kelvin ? " " : " °") << GetScaleAsString(temp.scale) << std::endl;
}

int main()
{
    auto temp = GetTemperatureFromUser();
    PrintTemperature(temp);

    auto results = GetCalculatedTemperature(temp);
    for (size_t i = 0; i < 3; i++)
    {
        PrintTemperature(*results);
        ++results;
    }
}
