//
// Created by Jan Kubow on 19/11/2024.
//

#ifndef VARIABLE_H
#define VARIABLE_H
#include <string>

#include "INode.h"


class Variable : public INode{
public:
    //Constructors
    explicit Variable(const std::string& newName);
    ~Variable();

    //User info func
    void printTree() const;
    void printValue() const;

    //Func
    const INode* evaluate(std::map<std::string, double> &varsMap) const;
    bool inputChild(INode* node, bool exchange, INode *nodeToSwitch);
    INode* traverseDown() const;
    bool isLeaf() const;

    std::queue<INode *> addChildrenToQueue(std::queue<INode *> nodeQueue) const;

    //getters&setters
    INode* getParent() const;
    void setParent(INode* node);
    std::string getStrValue() const;
    double getValue() const;
    const std::string &getFormula(std::string &formula) const;

private:
    std::string name;
    INode* parent;
    mutable double value;
};



#endif //VARIABLE_H
