//
// Created by Jan Kubow on 19/11/2024.
//

#ifndef NODE_H
#define NODE_H


#include <map>
#include <string>




class INode {
public:
    //Constructors
    virtual ~INode() {}

    //User info func
    virtual void printTree() const = 0;
    virtual void printValue() const = 0;

    //Func
    virtual const INode* evaluate(std::map<std::string, double> &varsMap) const = 0;
    virtual INode* getParent() const = 0;
    virtual void setParent(INode* node) = 0;
    virtual bool inputChild(INode* node, bool exchange) = 0;
    virtual std::string getValue() const = 0;
    virtual INode* traverseDown() const = 0;
    virtual bool isLeaf() const = 0;
    virtual INode* clone() const = 0;
    virtual std::string &getFormula(std::string &formula) = 0;

};


#endif //NODE_H
