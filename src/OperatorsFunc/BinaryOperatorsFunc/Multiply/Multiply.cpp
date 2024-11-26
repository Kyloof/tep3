// Multiply.cpp

#include "Multiply.h"
#include <sstream>
#include "Literal.h"

Multiply::Multiply() {}


//Functions
double Multiply::evaluate(std::map<std::string, double> &varsMap) const {
    const double leftDbl = getLeftChild()->evaluate(varsMap);
    const double rightDbl = getRightChild()->evaluate(varsMap);
    return leftDbl * rightDbl;
}



//getters
std::string Multiply::getStrValue() const {
    return "+";
}

