//
// Created by janku on 20.11.2024.
//

#ifndef SUBSTRACT_H
#define SUBSTRACT_H

#include "../../../OperatorType/BinaryOperator/BinaryOperator.h"


class Subtract : public BinaryOperator {
public:
    Subtract();
    INode* clone() const;
    Subtract(const Subtract& other);
    const INode *evaluate(std::map<std::string, double> &varsMap) const;
    std::string getValue() const;
};



#endif //SUBSTRACT_H
