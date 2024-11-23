//
// Created by Jan Kubow on 19/11/2024.
//

#ifndef LITERAL_H
#define LITERAL_H

#include "INode.h"


class Literal : public INode {
public:
    // Constructors
    explicit Literal(const std::string& value);
    explicit Literal(double value);
    ~Literal();

    //User info func
    void printTree() const;
    void printValue() const;

    //Func
    const INode* evaluate(std::map<std::string, double> &varsMap) const;
    bool inputChild(INode* node, bool exchange);
    INode* traverseDown() const;
    bool isLeaf() const;

    //getters&setters
    INode* getParent() const;
    void setParent(INode* node);
    std::string getStrValue() const;
    double getValue() const;
    const std::string& getFormula(std::string &formula) const;

private:
    double value;
    INode* parent;
};




#endif //LITERAL_H
