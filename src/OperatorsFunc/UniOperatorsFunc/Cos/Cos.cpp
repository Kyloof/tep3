//
// Created by janku on 20.11.2024.
//

#include "Cos.h"

#include <cmath>
#include <sstream>
#include "Literal.h"

Cos::Cos(){}

double Cos::evaluate(std::map<std::string, double> &varsMap) const {
    return new Literal(std::cos(getChild()->evaluate(varsMap)->getValue()));
}

std::string Cos::getStrValue() const{
    return "cos";
}



