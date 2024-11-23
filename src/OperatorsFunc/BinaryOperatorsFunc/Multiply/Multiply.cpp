// Multiply.cpp

#include "Multiply.h"
#include <sstream>
#include "Literal.h"

Multiply::Multiply() {}


//Functions
const INode* Multiply::evaluate(std::map<std::string, double> &varsMap) const {
    const double leftInt = getLeftChild()->evaluate(varsMap)->getValue();
    const double rightInt = getRightChild()->evaluate(varsMap)->getValue();
    return new Literal(leftInt * rightInt);
}


//getters
std::string Multiply::getStrValue() const {
    return "+";
}

