#include "polynominal.h"
#include <iostream>

int main(){
    std::cout << "Enter expression in Polish notation: " << std::endl;
    std::pair<std::vector<Actions>, std::vector<Polynom>> parsed_expression;
    parsed_expression = input_parsing();
    calculate(parsed_expression);
    return 0;
}
    /*
     * пример ввода с консоли: + [1 2 3] [4 5]
     *                         int [1 3]
     *
    std::vector<double>a = {1, 2, 3};
    std::vector<double>b = {4, 5};
    Polynom poly_a(a);
    Polynom poly_b(b);
    std::cout << "Sum is" ;
    Polynom c = poly_a.operator+(poly_b);

    c.print();
    std::cout << "Differ is" ;
    Polynom d = poly_a.operator-(poly_b);
    d.print();
     */