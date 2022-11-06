#include "polynominal.h"
#include <iostream>
#include <vector>
#include <regex>

Polynom::Polynom(std::vector<double>& coeff) {
    this->coeff = std::move(coeff);
};

Polynom::Polynom(int len){
    for (int i = 0; i < len; ++i){
        coeff.push_back(0);
    }
};

Polynom::Polynom(std::string input_data){
    while(input_data[0] == '[' || input_data[0] == ' ')
        input_data.erase(0, 1);

    while(input_data[input_data.size() - 1] == ']' || input_data[input_data.size() - 1] == ' ')
        input_data.erase(input_data.size() - 1, 1);


    int pos = 0;
    while ((pos = input_data.find(" ")) != std::string::npos) {
        coeff.push_back(stod(input_data.substr(0, pos)));
        input_data.erase(0, pos + 1);
    }
    coeff.push_back(stod(input_data));
};

Polynom Polynom::operator + (const Polynom& p){
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

Polynom Polynom::operator - (const Polynom& p){
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

Polynom Polynom::operator * (const Polynom& p){
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

std::vector<Actions> get_actions(std::string line) {
    std::vector<Actions> actions;

    std::istringstream iss(line);
    std::map <std::string, int> mapping;
    mapping["+"]  = SUM;
    mapping["-"]  = MINUS;
    mapping["*"] = MULTIPLY;
    mapping["int"]  = INTEGRAL;
    mapping["der"]  = DERIVATIVE;
    mapping[""]=EMP;
    std::string sign;
    while (getline(iss,sign, ' ')) {
        if (mapping[sign]==0){
            std::cerr<<"unknown sign";
            exit(-1);
        }

        switch (mapping[sign]) {
            case SUM:
                actions.insert(actions.begin(),SUM);
                break;
            case MINUS:
                actions.insert(actions.begin(),MINUS);
                break;
            case MULTIPLY:
                actions.insert(actions.begin(),MULTIPLY);
                break;
            case INTEGRAL:
                actions.insert(actions.begin(),INTEGRAL);
                break;
            case DERIVATIVE:
                actions.insert(actions.begin(),DERIVATIVE);
                break;
            case EMP:
                break;
            default:
                std::cerr << "incorrect line";
                exit(-1);
        }
    }
    return actions;
}

std::pair<std::vector<Actions>, std::vector<Polynom>> input_parsing() {
    std::vector<Actions> actions;
    std::vector<Polynom> polys;
    std::regex regular("(\\[[-?[:digit:]+ ]*\\])");
    std::cmatch result;
    int pos;
    std::string line;
    getline(std::cin, line);

    while (regex_search(line.c_str(), result, regular)) {
        Polynom poly(result[0]);
        pos = line.find(result[0]);
        line.erase(pos, result[0].length());
        polys.push_back(poly);
    }
    actions = get_actions(line);

    std::pair<std::vector<Actions>, std::vector<Polynom>> res;
    res.first = actions;
    res.second = polys;
    return res;
}

int calculate(std::pair<std::vector<Actions>, std::vector<Polynom>> parsed) {
    for (int i = 0; i < parsed.first.size(); ++i) {
        switch (parsed.first[i]) {
            case SUM:
                parsed.second[0] = parsed.second[0] + parsed.second[i + 1];
                break;
            case MINUS:
                parsed.second[0] = parsed.second[0] - parsed.second[i + 1];
                break;
            case MULTIPLY:
                parsed.second[0] = parsed.second[0] * parsed.second[i + 1];
                break;
            case DERIVATIVE:
                parsed.second[0] = parsed.second[0].diff();
                break;
            case INTEGRAL:
                parsed.second[0] = parsed.second[0].integral();
                break;
            default:
                break;
        }
    }
    parsed.second[0].print();
    return 0;
}
