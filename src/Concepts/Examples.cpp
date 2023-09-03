#include <type_traits>
#include <string>
#include <concepts>
#include <iostream>

template<typename T>
concept floating_point = std::is_floating_point_v<T>;

floating_point auto add(const floating_point auto first, const floating_point auto second)
{
	return first + second;
}

template <typename T>
    requires std::integral<T> ||
(std::invocable<T> &&
    std::integral<typename std::invoke_result<T>::type>)
void function(const T & x) {
    if constexpr (std::invocable<T>) {
        std::cout << "Result of call is " << x() << "\n";
    }
    else {
        std::cout << "Value is " << x << "\n";
    }
}


void Test()
{
	/*add(1.2, 1); // error*/
	add(1.2, 1.2); // no error
    function(1); // OK, integral
    function([]() { return 2; }); // OK, invocable, returns integral
    /*function(2.0); // Error*/
}