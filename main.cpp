#include "polynominal.h"
#include <iostream>
#include <vector>

int main(){
    std::vector<double>a = {1, 2, 3};
    std::vector<double>b = {4, 5, 6};
    Polynom poly_a(a);
    Polynom poly_b(b);
    std::cout << "Sum is" ;
    Polynom c = poly_a.operator+(poly_b);
    c.print();
    return 0;
}