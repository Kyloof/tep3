//
// Created by Jan Kubow on 19/11/2024.
//

#ifndef OPERATOR_H
#define OPERATOR_H
#include "ANode.h"


class Operator : public ANode {
public:
    Operator(const int& value);
    Operator(const Operator& value);
    Operator(int value);
    ~Operator();
};



#endif //OPERATOR_H
