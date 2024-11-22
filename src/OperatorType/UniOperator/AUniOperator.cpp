//
// Created by janku on 20.11.2024.
//

#include "AUniOperator.h"

AUniOperator::AUniOperator() : child(0) {}

AUniOperator::~AUniOperator() {
    delete child;
    child = 0;
}

INode* AUniOperator::getChild() const {
    return this->child;
}

INode *AUniOperator::traverseDown() const {
    return getChild();
}

bool AUniOperator::isLeaf() const {
    return getChild()!=0;
}


bool AUniOperator::hasChild() const {
    return this->child != 0;
}

void AUniOperator::allocateChild(INode* node) {
    this->child = node;
    node->setParent(this);
}

bool AUniOperator::inputChild(INode* node, const bool exchange) {
    if (exchange) {
        delete child;
        allocateChild(node);
        return true;
    }
    if (hasChild()) return false;
    allocateChild(node);
    return true;
}

void AUniOperator::printTree() const {
    printValue();
    if (hasChild()) {
        child->printTree();
    }
}

const std::string& AUniOperator::getFormula(std::string &formula) const {
    formula+=this->getStrValue() + " ";
    if(hasChild()) child->getFormula(formula);
    return formula;
}





