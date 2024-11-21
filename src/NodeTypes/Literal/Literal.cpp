//
// Created by Jan Kubow on 19/11/2024.
//

#include "Literal.h"
#include <iostream>
#include <sstream>

//Constructors
Literal::Literal(const std::string& value) : value(value), parent(0) {}

Literal::Literal(const double value) {
    std::ostringstream oss;
    oss << value;
    this->value = oss.str();
    parent = 0;
}

Literal::Literal(const Literal* literal) {
    this->value = literal->value;
    this->parent = 0;
}

Literal::~Literal() {}

INode* Literal::getParent() const {
    return this->parent;
}

void Literal::setParent(INode* node) {
    this->parent = node;
}

bool Literal::inputChild(INode* node, const bool exchange) {
    return false;
}

std::string Literal::getValue() const {
    return value;
}

void Literal::printValue() const {
    std::cout << value << " ";
}

const INode* Literal::evaluate(std::map<std::string, double> &varsMap) const {
    return this;
}

INode *Literal::traverseDown() const {
    return NULL;
}

bool Literal::isLeaf() const {
    return true;
}

void Literal::printTree() const {
    printValue();
}

INode *Literal::clone() const {
    return new Literal(this);
}





