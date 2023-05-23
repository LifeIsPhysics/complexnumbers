#include "mycomplex.h"

int main() {
    // TESTS
    Complex<double> c1{1.2, 2.7};
    Complex<double> c2{2.67124598765, .1289731824};

    print(add(c1, c2));
    print(conjugate(c1));
    print(reciprocal(c2));
    print(divide(c1, c2));
    print(subtract(c1, c2));
    print(multiply(c1, c2));
    print(squared(c1));
    return 0;
}
