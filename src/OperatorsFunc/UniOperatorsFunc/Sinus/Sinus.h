//
// Created by janku on 20.11.2024.
//

#ifndef SINUS_H
#define SINUS_H
#include "../../../OperatorType/UniOperator/AUniOperator.h"

class Sinus : public AUniOperator {
public:
    Sinus();

    //Functions
    const INode *evaluate(std::map<std::string, double> &varsMap) const;

    //getters
    std::string getStrValue() const;
};



#endif //SINUS_H
