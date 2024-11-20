//
// Created by Jan Kubow on 19/11/2024.
//

#ifndef LITERAL_H
#define LITERAL_H
#include "ANode.h"



class Literal : public ANode {
public:
    Literal(const int& value);
    Literal(const Literal& value);
    Literal(int value);
    ~Literal();

private:

};




#endif //LITERAL_H
