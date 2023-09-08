// 1. Create a function to calculate and return root(s) of a quadratic equasion
// in any given form. See the link below.
// https://en.wikipedia.org/wiki/Quadratic_equation
// If not obvious, use std::variant somehow.
// 2. Test your code.


/*
??? CalculateRoots(double a, double b, double c)
{
   // implementation goes here.
}
*/
#include <variant>

std::variant<double, std::pair<double, double>, std::complex<double>, std::pair<std::complex<double>, std::complex<double>>>
CalculateRoots(double a, double b, double c) {
    double temp = b * b - 4 * a * c;
    // Real one part
    if (temp > 0) {
        double rt = sqrt(temp);
        double x1 = (-b + rt) / (2 * a);
        double x2 = (-b - rt) / (2 * a);
        if (x1 == x2) {
            return x1;
        }
        else {
            return std::pair<double, double>{ x1, x2 };
        }
    }
    // Complex
    else {
        std::complex<float> tempComplex = temp;
        auto rt = sqrt(temp);
        auto x1 = (-b + rt) / (2 * a);
        auto x2 = (-b - rt) / (2 * a);
        if (x1 == x2) 
        {
            return x1;
        }
        else 
        {
            return std::pair<std::complex<double>, std::complex<double>>{ x1, x2 };
        }
    }
}