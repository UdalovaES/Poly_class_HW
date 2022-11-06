#pragma once
#include <string>
#include <vector>

class Polynom{
private:
    std::vector <double> coeff;
public:
    //конструкторы
    Polynom() = default;
    Polynom(std::vector<double> coeff);
    Polynom(int len);
    Polynom(std::string input_data);
    //Polynom(std::vector<Polynom> parsing_string, std::string data);

    // Операторы
    Polynom operator + (const Polynom& p2);
    Polynom operator - (const Polynom& p2);
    Polynom operator * (const Polynom& p2);
    Polynom diff();
    Polynom integral();

    void print();
    void parser(std::string input_data);
};

enum Actions {
    NONE,
    DERIVATIVE,
    INTEGRAL,
    MULTIPLY,
    SUM,
    MINUS,
    EMP,
};

std::vector<Actions> get_actions(std::string line);

std::pair<std::vector<Actions>, std::vector<Polynom>> input_parsing();

int calculate(std::pair<std::vector<Actions>, std::vector<Polynom>> parsed);