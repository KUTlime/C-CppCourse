#include <iostream>
#include "Templates.h"
#include <vector>

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
}