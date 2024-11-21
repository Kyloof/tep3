//
// Created by Jan Kubow on 19/11/2024.
//

#ifndef VARIABLE_H
#define VARIABLE_H
#include <string>

#include "INode.h"


class Variable : public virtual INode{
public:
    //Constructors
    explicit Variable(const std::string& newName);
    explicit Variable(const Variable* variable);

    ~Variable();

    //User info func
    void printTree() const;
    void printValue() const;

    //Func
    const INode* evaluate(std::map<std::string, double> &varsMap) const;
    INode* getParent() const;
    void setParent(INode* node);
    bool inputChild(INode* node, bool exchange);
    std::string getValue() const;
    INode* traverseDown() const;
    bool isLeaf() const;
    INode* clone() const;


private:
    std::string name;
    INode* parent;
};



#endif //VARIABLE_H
