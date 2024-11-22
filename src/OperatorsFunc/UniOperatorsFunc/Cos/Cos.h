//
// Created by janku on 20.11.2024.
//

#ifndef COS_H
#define COS_H
#include "../../../OperatorType/UniOperator/UniOperator.h"


class Cos : public UniOperator {
public:
    Cos();
    INode* clone() const;
    Cos(const Cos& other);
    const INode *evaluate(std::map<std::string, double> &varsMap) const;
    std::string getValue() const;
};


#endif //COS_H
