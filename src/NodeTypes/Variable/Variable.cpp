//
// Created by Jan Kubow on 19/11/2024.
//

#include "Variable.h"
#include <iostream>

#include "Literal.h"

//Constructors
Variable::Variable(const std::string& newName) : name(newName), parent(0), value(-1){}

Variable::~Variable() {}


//user info
void Variable::printValue() const {
    std::cout << getStrValue() << " ";
}

std::string Variable::createFormulaFromNode() const {
    printValue();
}


//Functions
double Variable::evaluate(std::map<std::string, double> &varsMap) const {
    const std::map<std::string, double>::const_iterator it = varsMap.find(name);
    this->value = it->second;
    return new Literal(it->second);
}

bool Variable::inputChild(INode *node, const bool change, INode *nodeToSwitch) {
    return false;
}

INode *Variable::traverseDown() const {
    return 0;
}

bool Variable::isLeaf() const {
    return true;
}

std::queue<INode *> Variable::addChildrenToQueue(std::queue<INode *> nodeQueue) const {return nodeQueue;}



//getters&setters
void Variable::setParent(INode *node) {
    parent = node;
}

INode *Variable::getParent() const {
    return parent;
}

std::string Variable::getStrValue() const {
    return name;
}

//not applicable
double Variable::getValue() const {
    if (value == -1) std::cout << "Value still not applied yet, please compile first." << "\n";
    return value;
}

const std::string& Variable::getFormula(std::string &formula) const {
    formula += getStrValue() + " ";
    return formula;
}











