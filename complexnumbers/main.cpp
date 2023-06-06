#include "my_complex.h"

int main() {
    // TESTS
    Complex c1{1., 1.};
    Complex c2{1., 2.};

    std::cout << c1.getReal() << '\n';          // 1
    std::cout << c2.getImag() << '\n';          // 2
    c1.add(c2).print();                         // 2+j3
    c1.subtract(c1).print();                    // 0+j0
    c1.add(c2).subtract(c2).print();            // 1+j1
    c1.multiply(c2).print();                    // -1+j3
    c1.squared().print();                       // 0+j2
    c1.divide(c2).print();                      // 0.6-j0.2
    c2.reciprocal().print();                    // 0.2-j0.4


    return 0;
}
