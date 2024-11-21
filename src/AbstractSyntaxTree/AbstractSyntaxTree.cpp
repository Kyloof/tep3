//
// Created by Jan Kubow on 19/11/2024.
//

#include "AbstractSyntaxTree.h"

#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <vector>

#include "Literal.h"
#include "Variable.h"
#include "../OperatorsFunc/BinaryOperatorsFunc/Addition/Addition.h"
#include "../OperatorsFunc/BinaryOperatorsFunc/Divide/Divide.h"
#include "../OperatorsFunc/BinaryOperatorsFunc/Multiply/Multiply.h"
#include "../OperatorsFunc/BinaryOperatorsFunc/Substract/Subtract.h"
#include "../OperatorsFunc/UniOperatorsFunc/Cos/Cos.h"
#include "../OperatorsFunc/UniOperatorsFunc/Sinus/Sinus.h"


AbstractSyntaxTree::AbstractSyntaxTree() : root(0), inputNode(root), varsSet(){}

AbstractSyntaxTree::AbstractSyntaxTree(const AbstractSyntaxTree &other) {

}

AbstractSyntaxTree& AbstractSyntaxTree::operator=(const AbstractSyntaxTree& other) {
    if (this == &other) return *this; // Self-assignment check.

    delete root;
    delete inputNode;

    root = copyTree(other.root);
    varsSet = other.varsSet;
    inputNode = root;

    return *this;
}

AbstractSyntaxTree::~AbstractSyntaxTree() {
    delete root;
    delete inputNode;
}

INode* AbstractSyntaxTree::createNode(const std::string& formula) {

    if (formula == "+") {
        return new Addition();
    } if (formula == "-") {
        return new Subtract();
    } if (formula == "*") {
        return new Multiply();
    } if (formula == "/") {
        return new Divide();
    } if (formula == "sin") {
        return new Sinus();
    } if (formula == "cos") {
        return new Cos();
    }
    bool isValid = true;
    for (int i = 0; i < formula.size(); i++) {
        if (!std::isdigit(formula[i]) && !std::isalpha(formula[i])) {
            isValid = false;
            std::cout << "Invalid character detected in formula: " << formula[i] << " - ignoring...\n";
            break;
        }
    }

    if (isValid) {
        bool isNumber = true;
        int i = 0;
        while (isNumber && i < formula.size()){
            if (!std::isdigit(formula[i])) {
                isNumber = false;
            }
            i++;
        }

        if (isNumber) {
            return new Literal(formula);
        }
        varsSet.insert(formula);
        return new Variable(formula);
    }

    std::cout << "Formula is invalid: " << formula << "\n";
    return NULL;
}

bool AbstractSyntaxTree::addFormula(const std::string& formula) {

    bool inputBool = false;
    INode* newNode = createNode(formula);
    if (root == 0) {
        delete root;
        delete inputNode;
        root = newNode;
        inputNode = root;
        return true;
    }
    while (!inputBool) {
        inputBool = inputNode->inputChild(newNode, false);
        if (inputBool == true) {
            inputNode = newNode;
            return true;
        }
        if (inputNode->getParent() == 0) {
            std::cout << "Fixing the formula: removing..." << "\n";
            return false;
        }
        inputNode = inputNode->getParent();
    }
    return false;
}



AbstractSyntaxTree& AbstractSyntaxTree::enter(const std::string &formula) {
    std::string currentFormula;
    for (int i = 0; i <= formula.size(); i++) {

        if (formula[i] == ' ' || i == formula.size()){
            const bool result = addFormula(currentFormula);
            if (!result) {
                std::cout<<"removed: ";
                for (int j = i - 1; j <= formula.size(); j++) {
                    std::cout << formula[j];
                }
                std::cout << "\n";
                return *this;
            }
            currentFormula = "";
            continue;
        }
        currentFormula += formula[i];
    }
    fixTree();
    return *this;
}

void AbstractSyntaxTree::fixTree() {
    if (root == 0) {
        std::cout << "The tree is empty...";
        return;
    }
    bool hadToFix = false;
    while(inputNode!=0) {
        bool inputBool = true;
        while (inputBool) {
            inputBool = inputNode->inputChild(new Literal(1), false);
            if(inputBool) hadToFix = true;
        }
        inputNode = inputNode->getParent();
    }
    if (hadToFix) {
        std::cout << "fixed formula: " << "\n";
        root->printTree();
        std::cout << "\n";
    }

}


std::string AbstractSyntaxTree::comp(const std::string &vars) const {
    std::istringstream iss(vars);
    std::vector<double> values;
    double value;

    while (iss >> value) {
        values.push_back(value);
    }

    if (values.size() != varsSet.size()) {
        std::cerr << "Error: Mismatch between number of variables and values provided.\n";
    }

    std::map<std::string, double> varsMap;

    std::set<std::string>::const_iterator varIt = varsSet.begin();
    std::vector<double>::const_iterator valIt = values.begin();

    for (; varIt != varsSet.end() && valIt != values.end(); ++varIt, ++valIt) {
        varsMap[*varIt] = *valIt;
    }

    std::map<std::string, double>::const_iterator mapIt;
    for (mapIt = varsMap.begin(); mapIt != varsMap.end(); ++mapIt) {
        std::cout << mapIt->first << " = " << mapIt->second << "\n";
    }

    return root->evaluate(varsMap)->getValue();
}

void AbstractSyntaxTree::join(const std::string &formula) {
    AbstractSyntaxTree other;
    other.enter(formula);
    varsSet.insert(other.varsSet.begin(), other.varsSet.end());
    const INode* nodeToJoin = root;
    if (root != 0) {
        while (!nodeToJoin->isLeaf()) {
            nodeToJoin=nodeToJoin->traverseDown();
        }
        INode* parentNode = nodeToJoin->getParent();
        parentNode->inputChild(other.root, true);

    }
    else {
        root = other.root;
    }
}

void AbstractSyntaxTree::vars() {
    std::copy(
        varsSet.begin(),
        varsSet.end(),
        std::ostream_iterator<std::string>(std::cout, " ")
        );
    std::cout << "\n";
}

void AbstractSyntaxTree::print() const {
    std::cout<<"printing tree..." << '\n';
    root->printTree();
    std::cout << "\n";
}

INode* AbstractSyntaxTree::copyTree(INode* originalNode) {
    if (originalNode == NULL) return NULL;

    INode* newNode = originalNode->clone();

    if (!newNode->isLeaf()) {
        INode* childNode = newNode->traverseDown(); // This assumes traverseDown() gives the first child
        while (childNode != nullptr) {
            INode* copiedChild = copyTree(childNode);  // Recursively copy each child
            newNode->inputChild(copiedChild, false);   // Set this child to the new node
            childNode = childNode->traverseDown();    // Move to the next child
        }
    }

    return newNode;
}




