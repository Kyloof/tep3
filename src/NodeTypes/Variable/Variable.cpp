//
// Created by Jan Kubow on 19/11/2024.
//

#include "Variable.h"
#include <iostream>

#include "Literal.h"

Variable::Variable(const std::string& newName) : name(newName), parent(0){}
Variable::Variable(const Variable* variable) {
    this->name = variable->name;
    this->parent = 0;
}
Variable::~Variable() {}


const INode *Variable::evaluate(std::map<std::string, double> &varsMap) const {
    std::map<std::string, double>::const_iterator it = varsMap.find(name);
    if (it != varsMap.end()) {
        return new Literal(it->second);
    } else {
        std::cerr << "Error: Variable '" << name << "' not found in varsMap.\n";
        return 0;
    }
}

void Variable::setParent(INode *node) {
    parent = node;
}

INode *Variable::getParent() const {
    return parent;
}

std::string Variable::getValue() const {
    return name;
}

bool Variable::inputChild(INode *node, const bool exchange) {
    return false;
}

void Variable::printValue() const {
    std::cout << getValue() << " ";
}

INode *Variable::traverseDown() const {
    return 0;
}

bool Variable::isLeaf() const {
    return true;
}

void Variable::printTree() const {
    printValue();
}

INode *Variable::clone() const {
    return new Variable(this);
}











