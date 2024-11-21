//
// Created by janku on 20.11.2024.
//

#ifndef SINUS_H
#define SINUS_H
#include "../../../OperatorType/UniOperator/UniOperator.h"

class Sinus : public UniOperator {
public:
    const INode *evaluate(std::map<std::string, double> &varsMap) const;
    std::string getValue() const;
};



#endif //SINUS_H
