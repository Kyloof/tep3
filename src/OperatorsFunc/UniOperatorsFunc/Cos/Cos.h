//
// Created by janku on 20.11.2024.
//

#ifndef COS_H
#define COS_H
#include "../../../OperatorType/UniOperator/AUniOperator.h"


class Cos : public AUniOperator {
public:
    Cos();

    //Functions
    const INode *evaluate(std::map<std::string, double> &varsMap) const;

    //getters
    std::string getStrValue() const;
};


#endif //COS_H
