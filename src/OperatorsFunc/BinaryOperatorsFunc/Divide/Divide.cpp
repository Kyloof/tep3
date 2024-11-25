// Divide.cpp

#include "Divide.h"
#include <sstream>
#include "Literal.h"

Divide::Divide() {}


//Functions
double Divide::evaluate(std::map<std::string, double> &varsMap) const {
    const double leftInt = getLeftChild()->evaluate(varsMap)->getValue();
    const double rightInt = getRightChild()->evaluate(varsMap)->getValue();
    return new Literal(leftInt / rightInt);
}


//getters
std::string Divide::getStrValue() const {
    return "/";
}



