//
// Created by janku on 20.11.2024.
//

#include "Cos.h"

#include <cmath>
#include <sstream>
#include "Literal.h"

Cos::Cos() : UniOperator(){}

Cos::Cos(const Cos &other)  : UniOperator(other) {
    this->parent = 0;
}

INode *Cos::clone() const {
    return new Cos(*this);
}


const INode* Cos::evaluate(std::map<std::string, double> &varsMap) const {
    std::string childValue = getChild()->evaluate(varsMap)->getValue();
    double x = 0.0;
    std::stringstream(childValue) >> x;
    double result = std::cos(x);

    std::stringstream resultStream;
    resultStream << result;
    const std::string resultStr = resultStream.str();

    return new Literal(resultStr);
}

std::string Cos::getValue() const{
    return "cos";
}

