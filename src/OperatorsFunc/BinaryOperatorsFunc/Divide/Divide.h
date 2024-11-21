//
// Created by janku on 20.11.2024.
//

#ifndef DIVIDE_H
#define DIVIDE_H
#include "../../../OperatorType/BinaryOperator/BinaryOperator.h"


class Divide : public BinaryOperator{
    const INode *evaluate(std::map<std::string, double> &varsMap) const;
    std::string getValue() const;
};



#endif //DIVIDE_H
