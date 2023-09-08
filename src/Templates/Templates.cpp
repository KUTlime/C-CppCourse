#include <iostream>
#include "Templates.h"
#include <vector>
#include <iostream>
#include <type_traits>

template <class T>
T AddThreeNumbers(T a, T b, T c)
{
    return a + b + c;
}

template <class T, class T2>
T AddThreeNumbers(T2 a, T b, T c)
{
    return a + b + c;
}

template <class T>
T FindMaxInArray(const T* array, const size_t & size)
{
    T max = array[0];
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}

template <class T>
size_t FindMaxIndexInArray(const T* array, const size_t& size)
{
    size_t indexOfMaxValue = 0;
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > array[indexOfMaxValue])
        {
            indexOfMaxValue = i;
        }
    }
    return indexOfMaxValue;
}

template <class T>
class MySmartPointer
{
public:
    MySmartPointer() { valueOnHeap = new T(); };
    ~MySmartPointer() 
    {
        std::cout << "Deleting smart pointer of " << typeid(T).name() << std::endl;
        delete valueOnHeap;
    };
    void SetValue(T value) { *valueOnHeap = value; }
    T GetValue() { return *valueOnHeap; }

private:
    T* valueOnHeap;
};

void TestSmartPointer()
{
    auto p1 = MySmartPointer<int>();
    auto p2 = MySmartPointer<std::vector<int>>();
    p1.SetValue(5);
    std::cout << p1.GetValue() << std::endl;

    p2.SetValue({ 1,2,3 });
    std::cout << p2.GetValue()[2] << std::endl;
}

// This function template will only be defined if T is an integral type
template<typename T, typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
void Print(T x) {
    std::cout << "The value is " << x << '\n';
}

// Similar implementation
template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
void PrintSimilar(T t) {
    std::cout << "foo(" << t << ") called\n";
}

// Conditionally select one of two types based on a condition
/*
The is_pointer struct is a type trait that checks if a given type is a pointer or not.
It has a static member variable value that is set to true
if the type is a pointer, and false otherwise.

The add_const_if_pointer alias template uses 
the std::conditional_t type trait to conditionally add 
the const qualifier to a given type if it is a pointer. 
If the type is not a pointer, it returns the original type.

In the main function, two calls are made to std::is_same_v 
to check if the resulting types of add_const_if_pointer<int> 
and add_const_if_pointer<int*> are equal to int and const int*, 
respectively. Since both calls return true, 
we can conclude that the code works as intended.
*/
template <typename T>
struct is_pointer {
    static constexpr bool value = false;
};

template <typename T>
struct is_pointer<T*> {
    static constexpr bool value = true;
};

template <typename T>
using add_const_if_pointer = std::conditional_t<is_pointer<T>::value, const T, T>;

// remove reference
/*
The foo function is overloaded to accept both a value and a reference of any type T.
The bar function is a template function that takes a single argument of type T.
However, the argument is passed by value, which means that if the argument is a reference type,
it will be copied and lose its reference-ness.

To avoid this, the std::remove_reference type trait is used to remove the reference from the type T
before passing it to foo.
This ensures that the correct overload of foo is called,
whether the argument is a value or a reference.
*/
template <typename T>
void foo(T t) 
{
    std::cout << "foo(T)\n";
}

template <typename T>
void foo(T& t) {
    std::cout << "foo(T&)\n";
}

template <typename T>
void bar(typename std::remove_reference<T>::type t) {
    foo(t);
}


int main()
{
    std::cout << AddThreeNumbers(1, 2, 3) << std::endl;
    std::cout << AddThreeNumbers(1.5, 2.5, 3.5) << std::endl;
    std::cout << AddThreeNumbers(1, 2.5, 3.5) << std::endl;
    std::cout << AddThreeNumbers(1.5, 2, 3) << std::endl;

    TestSmartPointer();

    int array[] = { 1, 2, 3, 4, 5 };
    size_t s1 = 5;
    std::cout << FindMaxInArray(array, s1) << std::endl;

    const double array2[] = { 1.1, 22, 3.3, 4.4, 50.05 };
    size_t s2 = 5;
    std::cout << FindMaxInArray(array2, s2) << std::endl;

    Print(42); // OK, int is an integral type
    // Print(3.14); // Error, double is not an integral type

    std::cout << std::boolalpha;
    std::cout << std::is_same_v<int, add_const_if_pointer<int>::type> << '\n'; // true
    std::cout << std::is_same_v<const int*, add_const_if_pointer<int*>::type> << '\n'; // true

    int x = 42;
    bar(x); // calls foo(T&)
    bar(3); // calls foo(T)
}