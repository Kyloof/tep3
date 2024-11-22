//
// Created by Jan Kubow on 19/11/2024.
//

#include "BinaryOperator.h"

BinaryOperator::BinaryOperator() : leftChild(0), rightChild(0) {}

BinaryOperator::~BinaryOperator() {
    delete leftChild;
    delete rightChild;
}

bool BinaryOperator::hasLeftChild() const {
    return leftChild != 0;
}

bool BinaryOperator::hasRightChild() const {
    return rightChild != 0;
}

void BinaryOperator::allocateLeftChild(INode* node) {
    this->leftChild = node;
    node->setParent(this);
}

void BinaryOperator::allocateRightChild(INode* node) {
    this->rightChild = node;
    node->setParent(this);
}

INode* BinaryOperator::getRightChild() const {
    return this->rightChild;
}

INode* BinaryOperator::getLeftChild() const {
    return this->leftChild;
}


bool BinaryOperator::inputChild(INode* node, const bool exchange) {
    if (exchange) {
        if (hasLeftChild()) {
            delete leftChild;
            allocateLeftChild(node);
            return true;
        }
        delete rightChild;
        allocateRightChild(node);
        return true;
    }
    if (hasLeftChild()) {
        if (hasRightChild()) {
            return false;
        }
        allocateRightChild(node);
        return true;
    }
    allocateLeftChild(node);
    return true;
}

bool BinaryOperator::isLeaf() const {
    return !hasLeftChild();
}

INode *BinaryOperator::traverseDown() const {
    if (hasLeftChild()) return leftChild;
    return 0;
}

void BinaryOperator::printTree() const {
    printValue();
    if (hasLeftChild()) {
        leftChild->printTree();
    }
    if (hasRightChild()) {
        rightChild->printTree();
    }
}

std::string &BinaryOperator::getFormula(std::string &formula) {
    formula += this->getValue() + " ";
    if(hasLeftChild()) leftChild->getFormula(formula);
    if(hasRightChild()) rightChild->getFormula(formula);
    return formula;
}









