//
// Created by janku on 20.11.2024.
//

#ifndef MULTIPLY_H
#define MULTIPLY_H
#include "INode.h"
#include "../../../OperatorType/BinaryOperator/ABinaryOperator.h"


class Multiply : public ABinaryOperator{
public:
    Multiply();

    //Functions
    const INode *evaluate(std::map<std::string, double> &varsMap) const;

    //getters
    std::string getStrValue() const;
};



#endif //MULTIPLY_H
