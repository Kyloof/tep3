// Divide.cpp

#include "Divide.h"
#include <sstream>
#include "Literal.h"

Divide::Divide() : BinaryOperator() {}

const INode* Divide::evaluate(std::map<std::string, double> &varsMap) const {
    const std::string leftValue = this->getLeftChild()->evaluate(varsMap)->getValue();
    const std::string rightValue = this->getRightChild()->evaluate(varsMap)->getValue();

    int leftInt, rightInt;

    std::stringstream(leftValue) >> leftInt;
    std::stringstream(rightValue) >> rightInt;

    if (rightInt == 0) {
        throw std::invalid_argument("Division by zero is undefined.");
    }

    const int result = leftInt / rightInt;

    std::stringstream resultStream;
    resultStream << result;
    const std::string resultStr = resultStream.str();

    return new Literal(resultStr);
}

std::string Divide::getValue() const {
    return "/";
}

Divide::Divide(const Divide &other)  : BinaryOperator(other) {
    parent = 0;
}

INode *Divide::clone() const {
    return (new Divide(*this));
}


