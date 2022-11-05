#include "polynominal.h"
#include <iostream>
#include <vector>

Polynom::Polynom(std::vector<double> coeff) {
    this->coeff = std::move(coeff);
}

Polynom::Polynom(int len){
    for (int i = 0; i < len; ++i){
        coeff.push_back(0);
    }
};

Polynom Polynom::operator + (Polynom p){
    Polynom summ_polynom(std::max(coeff.size(), p.coeff.size()));

    if (coeff.size() >= p.coeff.size()) {
        for (int i = 0; i < coeff.size(); ++i) {
            summ_polynom.coeff[i] = coeff[i];
        }
        for (int i = 0; i < p.coeff.size(); ++i) {
            summ_polynom.coeff[i] += p.coeff[i];
        }
    } else {
        for (int i = 0; i < p.coeff.size(); ++i) {
            summ_polynom.coeff[i] = p.coeff[i];
        }
        for (int i = 0; i < coeff.size(); ++i) {
            summ_polynom.coeff[i] += coeff[i];
        }
    }
    return summ_polynom;
};

Polynom Polynom::operator - (Polynom p){
    Polynom differ_polynom(std::max(coeff.size(), p.coeff.size()));

    if (coeff.size() >= p.coeff.size()) {
        for (int i = 0; i < coeff.size(); ++i) {
            differ_polynom.coeff[i] = coeff[i];
        }
        for (int i = 0; i < p.coeff.size(); ++i) {
            differ_polynom.coeff[i] -= p.coeff[i];
        }
    } else {
        for (int i = 0; i < p.coeff.size(); ++i) {
            differ_polynom.coeff[i] = p.coeff[i];
        }
        for (int i = 0; i < coeff.size(); ++i) {
            differ_polynom.coeff[i] -= coeff[i];
        }
    }
    return differ_polynom;
};

Polynom Polynom::operator * (Polynom p){
    int result = (coeff.size() - 1) + (p.coeff.size() - 1) + 1;
    Polynom mult_polynom(result);

    for (int i = 0; i < coeff.size(); i++)
        for (int j = 0; j < p.coeff.size(); j++)
            mult_polynom.coeff[i + j] += coeff[i] * p.coeff[j];

    return mult_polynom;
};

Polynom Polynom::diff(){
    Polynom diff_polynom(coeff.size() - 1);
    for (int i = 0; i < coeff.size()-1; ++i) {
        diff_polynom.coeff[i]=coeff[i+1]*(i+1);
    }
    return diff_polynom;
};

Polynom Polynom::integral(){
    Polynom int_polynom(coeff.size() + 1);
    for(int i = 1; i <= coeff.size(); i++)
        int_polynom.coeff[i] = coeff[i - 1] / i;
    return int_polynom;
};

void Polynom::print(){
    std::cout << "[" << coeff[0];
    for (int i = 1; i < coeff.size(); ++i){
        std::cout << " " << coeff[i];
    }
    std::cout << "]" << std::endl;
};
