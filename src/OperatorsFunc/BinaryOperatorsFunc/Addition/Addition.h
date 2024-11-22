//
// Created by janku on 20.11.2024.
//

#ifndef ADDITION_H
#define ADDITION_H
#include "../../../OperatorType/BinaryOperator/BinaryOperator.h"


class Addition : public BinaryOperator{
public:
    Addition();
    Addition(const Addition& other);
    const INode *evaluate(std::map<std::string, double> &varsMap) const;
    std::string getValue() const;
    INode* clone() const;
};



#endif //ADDITION_H
