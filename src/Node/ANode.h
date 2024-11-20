//
// Created by Jan Kubow on 19/11/2024.
//

#ifndef NODE_H
#define NODE_H
#include "NodeEnum.h"



class ANode {
public:
    virtual ~ANode() = 0;

private:
    int size;
    int value;
    // ANode tab[];

};


#endif //NODE_H
