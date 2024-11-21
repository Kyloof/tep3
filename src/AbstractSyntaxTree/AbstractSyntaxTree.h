//
// Created by Jan Kubow on 19/11/2024.
//

#ifndef ABSTRACTSYNTAXTREE_H
#define ABSTRACTSYNTAXTREE_H
#include <set>

#include "INode.h"
#include <string>



class AbstractSyntaxTree {

public:
    //Constructors - private
    AbstractSyntaxTree();
    AbstractSyntaxTree(const AbstractSyntaxTree& other);
    ~AbstractSyntaxTree();
    AbstractSyntaxTree& operator=(const AbstractSyntaxTree& other);


    //Console func
    AbstractSyntaxTree& enter(const std::string& formula);
    void vars();
    std::string comp(const std::string& vars) const;
    void join(const std::string& formula);
    void print() const;


private:
    INode* root;
    INode* inputNode;
    std::set<std::string> varsSet;
    bool addFormula(const std::string& formula);
    INode* createNode(const std::string& formula);
    INode* copyTree(INode* originalNode);


    void fixTree();
};



#endif //ABSTRACTSYNTAXTREE_H
