//
// Created by janku on 20.11.2024.
//

#include "UniOperator.h"

UniOperator::UniOperator() : child(0) {}

UniOperator::~UniOperator() {
    delete child;
}

INode* UniOperator::getChild() const {
    return this->child;
}

INode *UniOperator::traverseDown() const {
    return getChild();
}

bool UniOperator::isLeaf() const {
    return getChild()!=0;
}


bool UniOperator::hasChild() const {
    return this->child != 0;
}

void UniOperator::allocateChild(INode* node) {
    this->child = node;
    node->setParent(this);
}

bool UniOperator::inputChild(INode* node, const bool exchange) {
    if (exchange) {
        delete child;
        allocateChild(node);
        return true;
    }
    if (hasChild()) return false;
    allocateChild(node);
    return true;
}

void UniOperator::printTree() const {
    printValue();
    if (hasChild()) {
        child->printTree();
    }
}

std::string &UniOperator::getFormula(std::string &formula) {
    formula+=this->getValue() + " ";
    if(hasChild()) child->getFormula(formula);
    return formula;
}





