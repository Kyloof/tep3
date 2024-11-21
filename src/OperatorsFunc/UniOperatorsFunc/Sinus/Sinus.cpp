//
// Created by janku on 20.11.2024.
//

#include "Sinus.h"

#include <cmath>
#include <sstream>
#include "Literal.h"


const INode *Sinus::evaluate(std::map<std::string, double> &varsMap) const {
    std::string childValue = getChild()->evaluate(varsMap)->getValue();
    double x = 0.0;
    std::stringstream(childValue) >> x;
    double result = std::cos(x);

    std::stringstream resultStream;
    resultStream << result;
    const std::string resultStr = resultStream.str();

    return new Literal(resultStr);
}


std::string Sinus::getValue() const {
    return "sin";
}

