//
// Created by janku on 20.11.2024.
//

#include "Sinus.h"

#include <cmath>
#include <sstream>
#include "Literal.h"

Sinus::Sinus() {}

double Sinus::evaluate(std::map<std::string, double> &varsMap) const {
    return std::sin(getChild()->evaluate(varsMap));
}


std::string Sinus::getStrValue() const {
    return "sin";
}

