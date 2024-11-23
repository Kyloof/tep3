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

    //abstract
    const INode* evaluate(std::map<std::string, double> &varsMap) const = 0;
    bool inputChild(INode* node, bool exchange) = 0;
    std::string getStrValue() const = 0;
    INode* traverseDown() const = 0;
    void printTree() const = 0;
    bool isLeaf() const = 0;
    const std::string &getFormula(std::string &formula) const = 0;

    //getters&setters
    INode* getParent() const;
    void setParent(INode* node);
    void printValue() const;
    double getValue() const;


protected:
    INode* parent;
};

#endif //AOPERATOR_H
