#include <iostream>

class Real
{
public:
	Real() : Value(0) {};
	explicit Real(double value) : Value(value) {};
	double Value;
};

class Imaginary
{
public:
	Imaginary() : Value(0) {};
	explicit Imaginary(double value) : Value(value) {};
	double getValue() const noexcept
	{
		return Value;
	}
	void setValue(double value) noexcept
	{
		Value = value;
	}
	friend class Complex;
private:
	double Value;
};

class Complex
{
public:
	Complex(Real real, Imaginary imag) : realPart(real), imaginaryPart(imag) {};
	//Complex(double real) : realPart(real), imaginaryPart(0) {};
	Complex() : Complex(Real(0), Imaginary(0)){};
private:
	Real realPart;
	Imaginary imaginaryPart;
};
class ComplexV2
{
public:
	ComplexV2(Real real, Imaginary imag) { Create(real, imag); };
	ComplexV2() {Create(Real(0), Imaginary(0)); };
private:
	void Create(Real real, Imaginary imaginary) { realPart = real; imaginaryPart = imaginary; };
	Real realPart;
	Imaginary imaginaryPart;
};

int main()
{
	Complex c();
}