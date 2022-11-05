#pragma once
#include <string>
#include <vector>

class Polynom{
private:
    std::vector <double> coeff;

public:
    //конструкторы
    //Polynom() = default;
    Polynom(std::vector<double> coeff);
    Polynom(int len);

    // Операторы
    Polynom operator + (Polynom p2);
    Polynom operator - (Polynom p2);
    Polynom operator * (Polynom p2);
    Polynom diff();
    Polynom integral();

    void print();
};
