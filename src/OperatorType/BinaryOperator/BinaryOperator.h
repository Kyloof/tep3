//
// Created by Jan Kubow on 19/11/2024.
//

#ifndef OPERATOR_H
#define OPERATOR_H
#include "AOperator.h"
#include "INode.h"


class BinaryOperator : public AOperator {
public:
    BinaryOperator();
    ~BinaryOperator();

    //virtual
    virtual const INode* evaluate(std::map<std::string, double> &) const = 0;
    virtual std::string getValue() const = 0;
    virtual INode* clone() const = 0;
    //func
    void allocateLeftChild(INode* node);
    void allocateRightChild(INode* node);
    INode* getLeftChild() const;
    INode* getRightChild() const;
    bool hasLeftChild() const;
    bool hasRightChild() const;
    bool inputChild(INode* node, bool exchange);
    bool isLeaf() const;
    INode* traverseDown() const;
    void printTree() const;
    std::string &getFormula(std::string &formula);

private:
    INode* leftChild;
    INode* rightChild;

};



#endif //OPERATOR_H
