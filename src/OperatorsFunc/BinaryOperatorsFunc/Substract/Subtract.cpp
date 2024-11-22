// Subtraction.cpp

#include "Subtract.h"
#include <sstream>
#include "Literal.h"

Subtract::Subtract() : BinaryOperator() {}

const INode* Subtract::evaluate(std::map<std::string, double> &varsMap) const {
    const std::string leftValue = this->getLeftChild()->evaluate(varsMap)->getValue();
    const std::string rightValue = this->getRightChild()->evaluate(varsMap)->getValue();

    int leftInt, rightInt;

    std::stringstream(leftValue) >> leftInt;
    std::stringstream(rightValue) >> rightInt;
    const int result = leftInt - rightInt;

    std::stringstream resultStream;
    resultStream << result;
    const std::string resultStr = resultStream.str();

    return new Literal(resultStr);
}

std::string Subtract::getValue() const {
    return "-";
}

Subtract::Subtract(const Subtract &other)  : BinaryOperator(other) {
    parent = 0;
}

INode *Subtract::clone() const {
    return (new Subtract(*this));
}
