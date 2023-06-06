/*
*   Created by berke on 5/23/23.
*
*   Complex numbers, and complex number arithmetic.
*/


#ifndef MY_COMPLEX_H
#define MY_COMPLEX_H

#include "my_math.h"
#include <cassert>
#include <iostream>

template<typename T>
class Complex{
private:
    T mReal {0};
    T mImag {0};

public:
    Complex() = default;
    Complex(T real, T imag): mReal{ real }, mImag{ imag }{}

    [[maybe_unused]] Complex conjugate()
    {
        mImag = -mImag;
        return *this;
    }

    //getter
    [[maybe_unused]] auto getReal(){
        return mReal;
    }
    [[maybe_unused]] auto getImag(){
        return mImag;
    }
    //operations
    [[maybe_unused]] Complex add(const Complex& z)
    {
        return {mReal + z.mReal, mImag + z.mImag};
    }
    [[maybe_unused]] Complex subtract(const Complex& z)
    {
        return {mReal - z.mReal, mImag - z.mImag};
    }
    [[maybe_unused]] Complex multiply(const Complex& z)
    {
        return {mReal*z.mReal - mImag*z.mImag, mReal*z.mImag + mImag*z.mReal};
    }
    [[maybe_unused]] Complex squared()
    {
        // Needed because reference to (*this).mReal is passed to temp in multiply member function
        Complex<T> temp{ *this };
        return (*this).multiply(temp);
    }
    [[maybe_unused]] Complex divide(const Complex& z)
    {
        assert(!isZero(z.mReal) && !isZero(z.mImag) && "Division by Zero Error");
        //auto temp{ mReal };
        auto denominator { z.mReal*z.mReal + z.mImag*z.mImag };

        return {(mReal*z.mReal + mImag*z.mImag) / denominator, (mImag*z.mReal - mReal*z.mImag) / denominator};
    }
    [[maybe_unused]] Complex reciprocal() {
        Complex numerator{1, 0};
        Complex denominator{*this};
        return numerator.divide(denominator);
    }
    // print format
    [[maybe_unused]] void print()
    {
        if(mImag >= 0)
            std::cout << mReal << "+j" << mImag << '\n';
        else
            std::cout << mReal << "-j" << -mImag << '\n';
    }

};
template<typename T>
Complex(T, T) -> Complex<T>;// For class template argument deduction

/*
TODO:
    * Operator overloading
    * Square root solutions (how to implement list/tuple?????)
    * log, exp, sin, cos, tan, ...
    * Exponentiation
    * polar form
*/


#endif //MY_COMPLEX_H
