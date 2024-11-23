//
// Created by janku on 20.11.2024.
//

#include "Sinus.h"

#include <cmath>
#include <sstream>
#include "Literal.h"

Sinus::Sinus() {}

const INode *Sinus::evaluate(std::map<std::string, double> &varsMap) const {
    return new Literal(std::sin(getChild()->evaluate(varsMap)->getValue()));
}


std::string Sinus::getStrValue() const {
    return "sin";
}

