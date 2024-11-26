//
// Created by janku on 20.11.2024.
//

#include "Addition.h"
#include <sstream>
#include "Literal.h"

Addition::Addition() {}


//Functions
double Addition::evaluate(std::map<std::string, double> &varsMap) const {
    const double leftDbl = getLeftChild()->evaluate(varsMap);
    const double rightDbl = getRightChild()->evaluate(varsMap);
    return leftDbl + rightDbl;
}


//getters
std::string Addition::getStrValue() const {
    return "+";
}




