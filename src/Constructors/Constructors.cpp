#include <iostream>
#include <vector>

class Complex
{
public:
	Complex(double real, double imag) : realPart(real), imaginaryPart(imag) {};
	Complex(double real) : realPart(real), imaginaryPart(0) {};
	Complex() : Complex(0, 0) {};
private:
	double realPart;
	double imaginaryPart;
};

class ComplexV1
{
public:
	explicit ComplexV1(double real, double imag) : realPart(real), imaginaryPart(imag) {};
	explicit ComplexV1(double real) : realPart(real), imaginaryPart(0) {};
	explicit ComplexV1() : ComplexV1(0, 0) {};
private:
	double realPart;
	double imaginaryPart;
};

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
	friend class ComplexV2;
private:
	double Value;
};

class ComplexV2
{
public:
	ComplexV2(Real real, Imaginary imag) : realPart(real), imaginaryPart(imag) {};
	//Complex(double real) : realPart(real), imaginaryPart(0) {};
	ComplexV2() : ComplexV2(Real(0), Imaginary(0)){};
private:
	Real realPart;
	Imaginary imaginaryPart;
};

class ComplexV3
{
public:
	ComplexV3(Real real, Imaginary imag) { Create(real, imag); };
	ComplexV3() {Create(Real(0), Imaginary(0)); };
private:
	void Create(Real real, Imaginary imaginary) { realPart = real; imaginaryPart = imaginary; };
	Real realPart;
	Imaginary imaginaryPart;
};

void Test()
{
	using std::vector;
}

void Test(Real real, Imaginary imaginary)
{
}

int main()
{
	Complex c = {0, 1};
	Complex c1 = 1;
	ComplexV1 c2(0, 1);

	ComplexV2 d = { }; // Not really good.
	// ComplexV2 d = {0, 1};
	ComplexV2 d = { Real(0), Imaginary(0) };
}