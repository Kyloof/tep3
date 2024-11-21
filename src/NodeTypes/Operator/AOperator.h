//
// Created by janku on 20.11.2024.
//

#ifndef AOPERATOR_H
#define AOPERATOR_H

#include "INode.h"

class AOperator : public INode {
public:
    //Constructors
    ~AOperator();
    AOperator();

    //virtual
    virtual const INode* evaluate(std::map<std::string, double> &varsMap) const = 0;
    virtual bool inputChild(INode* node, bool exchange) = 0;
    virtual std::string getValue() const = 0;
    virtual INode* traverseDown() const = 0;
    virtual void printTree() const = 0;
    virtual bool isLeaf() const = 0;
    virtual INode* clone() const = 0;

    //non virtual
    INode* getParent() const;
    void setParent(INode* node);
    void printValue() const;


protected:
    INode* parent;
};

#endif //AOPERATOR_H
