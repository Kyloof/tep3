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
    //Constructors
    AbstractSyntaxTree();
    AbstractSyntaxTree(const AbstractSyntaxTree& other);
    ~AbstractSyntaxTree();

    //Operators
    AbstractSyntaxTree& operator=(const AbstractSyntaxTree& other);
    AbstractSyntaxTree operator+(const AbstractSyntaxTree& other) const;


    //Functions
    std::string vars();
    std::string comp(const std::string& vars) const;
    void join(const std::string& formula);
    std::string returnFormula() const;
    bool partialSwap(AbstractSyntaxTree& other, const std::string& token);
    std::string fixTree();
    void deleteTree();
    bool addFormula(const std::string& formula, bool isNumber);
    std::string enter(const std::string& formula);



private:
    INode* root;
    INode* inputNode;
    std::set<std::string> varsSet;
    INode* createNode(const std::string& formula, bool isNumber);
    INode* searchTokenBFS(const std::string& token) const;
};



#endif //ABSTRACTSYNTAXTREE_H
