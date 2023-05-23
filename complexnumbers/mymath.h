//
// Created by berke on 5/23/23.
//

#ifndef MYMATH_H
#define MYMATH_H

#include <algorithm>
#include <cmath>

template<typename T>
bool isZero(T a, double absEpsilon = 1e-12)
{
    return (std::abs(static_cast<double>(a)) <= absEpsilon);
}

#endif //MYMATH_H
