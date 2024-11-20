//
// Created by Jan Kubow on 19/11/2024.
//

#ifndef ABSTRACTSYNTAXTREE_H
#define ABSTRACTSYNTAXTREE_H
#include "Node.h"
#include <string>



class AbstractSyntaxTree {

public:
    //Constructors - private
    AbstractSyntaxTree(int value);
    AbstractSyntaxTree(const AbstractSyntaxTree& other);
    ~AbstractSyntaxTree();
    AbstractSyntaxTree& operator=(const AbstractSyntaxTree& other);


    //Console func
    void enter(const std::string& formula);
    void vars();
    void comp(const std::string& vars);
    void join(const std::string& formula);

    //

private:
    ANode* root;
};



#endif //ABSTRACTSYNTAXTREE_H
