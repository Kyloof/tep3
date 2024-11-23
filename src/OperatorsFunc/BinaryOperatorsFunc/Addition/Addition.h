//
// Created by janku on 20.11.2024.
//

#ifndef ADDITION_H
#define ADDITION_H
#include "../../../OperatorType/BinaryOperator/ABinaryOperator.h"


class Addition : public ABinaryOperator{
public:
    Addition();

    //Functions
    const INode *evaluate(std::map<std::string, double> &varsMap) const;

    //getters
    std::string getStrValue() const;
};



#endif //ADDITION_H
