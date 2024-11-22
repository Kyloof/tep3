// Multiply.cpp

#include "Multiply.h"
#include <sstream>
#include "Literal.h"

Multiply::Multiply() : BinaryOperator() {}

const INode* Multiply::evaluate(std::map<std::string, double> &varsMap) const {
    const std::string leftValue = this->getLeftChild()->evaluate(varsMap)->getValue();
    const std::string rightValue = this->getRightChild()->evaluate(varsMap)->getValue();

    int leftInt, rightInt;

    std::stringstream(leftValue) >> leftInt;
    std::stringstream(rightValue) >> rightInt;
    const int result = leftInt * rightInt;

    std::stringstream resultStream;
    resultStream << result;
    const std::string resultStr = resultStream.str();

    return new Literal(resultStr);
}

std::string Multiply::getValue() const {
    return "*";
}

Multiply::Multiply(const Multiply &other)  : BinaryOperator(other) {
    parent = 0;
}

INode *Multiply::clone() const {
    return (new Multiply(*this));
}
