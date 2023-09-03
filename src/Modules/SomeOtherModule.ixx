export module SomeOtherModule;
export void MyFunc() {};
import <string>;

export class MyClass
{
public:
	MyClass(std::string_view s) : s(s) {};
	~MyClass();

private:
	std::string s;
};

export template<typename T>
concept Greater = requires(T a, T b) {
	{ a > b } -> std::convertible_to<bool>;
};


export template<typename T>
T Max(const T& a, const T& b)
{
	return a > b ? a : b;
}
