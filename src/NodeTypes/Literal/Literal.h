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
    explicit Literal(const Literal* literal);
    ~Literal();

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
    std::string &getFormula(std::string &formula);


private:
    std::string value;
    INode* parent;
};




#endif //LITERAL_H
