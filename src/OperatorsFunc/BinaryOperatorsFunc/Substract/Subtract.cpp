// Subtraction.cpp

#include "Subtract.h"
#include <sstream>
#include "Literal.h"

Subtract::Subtract() {}


//Functions
double Subtract::evaluate(std::map<std::string, double> &varsMap) const {
    const double leftDbl = getLeftChild()->evaluate(varsMap);
    const double rightDbl = getRightChild()->evaluate(varsMap);
    return leftDbl - rightDbl;
}



//getters
std::string Subtract::getStrValue() const {
    return "-";
}

