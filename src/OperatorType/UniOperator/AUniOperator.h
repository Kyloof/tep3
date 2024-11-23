//
// Created by janku on 20.11.2024.
//

#ifndef UNIOPERATOR_H
#define UNIOPERATOR_H
#include "AOperator.h"
#include "INode.h"


class AUniOperator : public AOperator {

public:
    AUniOperator();
    ~AUniOperator();

    //virtual
    const INode* evaluate(std::map<std::string, double> &varsMap) const = 0;
    std::string getStrValue() const = 0;

    //user info
    void printTree() const;

    //Functions
    bool hasChild() const;
    void allocateChild(INode* node);
    bool inputChild(INode* node, bool exchange);
    INode* traverseDown() const;
    bool isLeaf() const;

    //getters&setters
    INode* getChild() const;
    const std::string &getFormula(std::string &formula) const;

private:
    INode* child;
};



#endif //UNIOPERATOR_H
