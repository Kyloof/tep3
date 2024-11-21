//
// Created by janku on 20.11.2024.
//

#ifndef UNIOPERATOR_H
#define UNIOPERATOR_H
#include "AOperator.h"
#include "INode.h"


class UniOperator : public AOperator {

public:
    UniOperator();
    ~UniOperator();

    //virtual
    virtual const INode* evaluate(std::map<std::string, double> &varsMap) const = 0;
    virtual std::string getValue() const = 0;

    //funcs
    INode* getChild() const;
    bool hasChild() const;
    void allocateChild(INode* node);
    bool inputChild(INode* node, bool exchange);
    INode* traverseDown() const;
    bool isLeaf() const;
    void printTree() const;

private:
    INode* child;
};



#endif //UNIOPERATOR_H
