/*
*   Created by berke on 5/23/23.
*
*   Complex numbers, and complex number arithmetic.
*/


#ifndef COMPLEX_H
#define COMPLEX_H

#include "mymath.h"
#include <cassert>
#include <iostream>

template<typename T>
struct Complex
{
    T real {};
    T imag {};
};

template<typename T>
[[maybe_unused]] Complex<T> conjugate(const Complex<T>& z)
{
    return {z.real, -z.imag};
}

template<typename T>
[[maybe_unused]] Complex<T> add(const Complex<T>& x, const Complex<T>& y)
{
    return {x.real + y.real, x.imag + y.imag};
}

template<typename T>
[[maybe_unused]] Complex<T> subtract(const Complex<T>& x, const Complex<T>& y)
{
    return {x.real - y.real, x.imag - y.imag};
}

template<typename T>
[[maybe_unused]] Complex<T> multiply(const Complex<T>& x, const Complex<T>& y)
{
    return {x.real*y.real - x.imag*y.imag, x.real*y.imag + x.imag*y.real};
}

template<typename T>
[[maybe_unused]] Complex<T> squared(const Complex<T>& z)
{
    return multiply(z, z);
}


template<typename T>
[[maybe_unused]] Complex<double> divide(const Complex<T>& x, const Complex<T>& y)
{
    assert(!isZero(y.real) && !isZero(y.real) && "Division by Zero Error");
    return { static_cast<double>(x.real*y.real + x.imag*y.imag)/(y.real*y.real + y.imag*y.imag) ,
             static_cast<double>(x.imag*y.real - x.real*y.imag)/(y.real*y.real + y.imag*y.imag)};
}

template<typename T>
[[maybe_unused]] Complex<double> reciprocal(const Complex<T> &z) {
    const Complex<T> temp{1, 0};
    return divide(temp, z);
}

/*
TODO:
    * Square root (how to implement list/tuple?????)
    * log, exp, sin, cos, tan, ...
    * Exponentiation
    * Multiplication and division in polar form ???
*/

template<typename T>
[[maybe_unused]] void print(const Complex<T> z)
{
    if(z.imag >= 0)
    {
        std::cout << z.real << "+j" << z.imag << '\n';
    }
    else if(z.imag < 0)
    {
        std::cout << z.real << "-j" << -z.imag << '\n';
    }
}

#endif //COMPLEX_H
