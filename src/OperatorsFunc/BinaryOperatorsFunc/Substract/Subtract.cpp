// Subtraction.cpp

#include "Subtract.h"
#include <sstream>
#include "Literal.h"

Subtract::Subtract() {}


//Functions
double Subtract::evaluate(std::map<std::string, double> &varsMap) const {
    const double leftInt = getLeftChild()->evaluate(varsMap)->getValue();
    const double rightInt = getRightChild()->evaluate(varsMap)->getValue();
    return new Literal(leftInt - rightInt);
}


//getters
std::string Subtract::getStrValue() const {
    return "-";
}

