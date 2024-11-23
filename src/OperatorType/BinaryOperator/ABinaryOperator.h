//
// Created by Jan Kubow on 19/11/2024.
//

#ifndef OPERATOR_H
#define OPERATOR_H
#include "AOperator.h"
#include "INode.h"


class ABinaryOperator : public AOperator {
public:
    ABinaryOperator();
    ~ABinaryOperator();

    //virtual
    const INode* evaluate(std::map<std::string, double>& varsMap) const = 0;
    std::string getStrValue() const = 0;

    //user info
    void printTree() const;

    //func
    void allocateLeftChild(INode* node);
    void allocateRightChild(INode* node);
    bool hasLeftChild() const;
    bool hasRightChild() const;
    bool inputChild(INode* node, bool exchange);
    INode* traverseDown() const;
    bool isLeaf() const;

    //getters&setters
    const std::string &getFormula(std::string &formula) const;
    INode* getLeftChild() const;
    INode* getRightChild() const;

private:
    INode* leftChild;
    INode* rightChild;

};



#endif //OPERATOR_H
