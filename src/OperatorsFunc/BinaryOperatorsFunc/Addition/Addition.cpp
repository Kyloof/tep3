//
// Created by janku on 20.11.2024.
//

#include "Addition.h"
#include <sstream>
#include "Literal.h"

Addition::Addition() {}


//Functions
double Addition::evaluate(std::map<std::string, double> &varsMap) const {
    const double leftInt = getLeftChild()->evaluate(varsMap)->getValue();
    const double rightInt = getRightChild()->evaluate(varsMap)->getValue();
    return new Literal(leftInt + rightInt);
}


//getters
std::string Addition::getStrValue() const {
    return "+";
}




