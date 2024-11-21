//
// Created by janku on 20.11.2024.
//

#ifndef MULTIPLY_H
#define MULTIPLY_H
#include "INode.h"
#include "../../../OperatorType/BinaryOperator/BinaryOperator.h"


class Multiply : public BinaryOperator{
    const INode *evaluate(std::map<std::string, double> &varsMap) const;
    std::string getValue() const;
};



#endif //MULTIPLY_H
