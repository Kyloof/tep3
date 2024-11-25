//
// Created by Jan Kubow on 19/11/2024.
//

#include "AbstractSyntaxTree.h"

#include <iostream>
#include <iterator>
#include <string>
#include <map>
#include <queue>
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
    root = 0;
    inputNode = 0;
    if (other.root != 0) {
    std::string* formula = new std::string;
    this->enter(other.root->getFormula(*formula));
    delete formula;
    }
}

AbstractSyntaxTree& AbstractSyntaxTree::operator=(const AbstractSyntaxTree& other) {
    if (this == &other) return *this;
    std::string* formula = new std::string;
    this->enter(other.root->getFormula(*formula));
    delete formula;
    return *this;
}

AbstractSyntaxTree AbstractSyntaxTree::operator+(const AbstractSyntaxTree& other) const {
    AbstractSyntaxTree newTree = *this;
    std::string* formula = new std::string;
    newTree.join(other.root->getFormula(*formula));
    delete formula;

    return newTree;
}

AbstractSyntaxTree::~AbstractSyntaxTree() {
    if (root != 0 && root->getParent()==0) {
        delete root;
        root = NULL;
    }
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
            std::cout<<"Invalid character " << formula[i] << " detected.";
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

    std::cout<< "Formula is invalid: " + formula + "\n";
    return NULL;
}

bool AbstractSyntaxTree::addFormula(const std::string& formula) {

    bool inputBool = false;
    INode* newNode = createNode(formula);
    if (newNode == NULL) {
        delete newNode;
        return true;
    }
    if (root == 0) {
        root = newNode;
        inputNode = root;
        return true;
    }
    while (!inputBool) {
        inputBool = inputNode->inputChild(newNode, false, NULL);
        if (inputBool == true) {
            inputNode = newNode;
            return true;
        }
        if (inputNode->getParent() == 0) {
            std::cout<< "Fixing the formula: removing... \n";
            return false;
        }
        inputNode = inputNode->getParent();
    }
    return false;
}



AbstractSyntaxTree& AbstractSyntaxTree::enter(const std::string &formula) {

    delete root;
    root = NULL;

    inputNode = NULL;

    std::string currentFormula;
    for (int i = 0; i <= formula.size(); i++) {

        if (formula[i] == ' ' || i == formula.size()  && !currentFormula.empty()){
            const bool result = addFormula(currentFormula);
            if (!result) {
                std::string removed;
                removed += "removed: ";
                for (int j = i - 1; j <= formula.size(); j++) {
                    removed += formula[j];
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
        std::cout<< "The tree is empty... \n" ;
        return;
    }
    bool hadToFix = false;

    //fix children
    while(inputNode!=root) {
        if (inputNode->inputChild(new Literal(1), false, NULL)) hadToFix = true;
        inputNode = inputNode->getParent();
    }

    //fix root
    while (inputNode->inputChild(new Literal(1), false, NULL)) {
        hadToFix = true;
    }

    if (hadToFix) {
        std::cout<<"fixed formula: \n";
        root->createFormulaFromNode();
        std::cout << "\n";
    }

}


std::string AbstractSyntaxTree::comp(const std::string &vars) const {
    if (root == NULL) {
        return "tree is empty \n" ;
    }
    std::istringstream iss(vars);
    std::vector<double> values;
    double value;

    while (iss >> value) {
        values.push_back(value);
    }

    if (values.size() != varsSet.size()) {
        return "Number of variables is not equal to values entered. Please try again... \n";
    }

    std::map<std::string, double> varsMap;
    std::set<std::string>::const_iterator varIt = varsSet.begin();
    std::vector<double>::const_iterator valIt = values.begin();

    for (; varIt != varsSet.end() && valIt != values.end(); ++varIt, ++valIt) {
        varsMap[*varIt] = *valIt;
    }

    for (std::map<std::string, double>::const_iterator mapIt = varsMap.begin(); mapIt != varsMap.end(); ++mapIt) {
        std::cout << mapIt->first << " = " << mapIt->second << "\n";
    }

    return root->evaluate(varsMap)->getStrValue();
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
        if (parentNode != 0) parentNode->inputChild(other.root, true, NULL);
        else {
            delete root;
            root = NULL;
            this->enter(formula);
        }
    }
    else {
        *this = other;
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
    if (root == NULL) {
        std::cout<<"tree is empty" << '\n';
        return;
    }
    std::cout<<"printing tree..." << '\n';
    root->createFormulaFromNode();
    std::cout << "\n";
}

INode* AbstractSyntaxTree::searchTokenBFS(std::string token) {
    std::queue<INode*> nodeQueue;
    nodeQueue.push(root);

    while (!nodeQueue.empty()) {
        INode* currentNode = nodeQueue.front();
        nodeQueue.pop();

        if (currentNode->getStrValue() == token) return currentNode;
        nodeQueue = currentNode->addChildrenToQueue(nodeQueue);
    }
    return NULL;
}

bool AbstractSyntaxTree::partialSwap(AbstractSyntaxTree &other, const std::string& token) {

    INode* thisNode = this->searchTokenBFS(token);
    INode* otherNode = other.searchTokenBFS(token);
    if (thisNode == NULL || otherNode == NULL) return false;

    if (thisNode == this->root) this->root = otherNode;
    else thisNode->getParent()->inputChild(otherNode, true, thisNode);

    if (otherNode == other.root) other.root = thisNode;
    else otherNode->getParent()->inputChild(thisNode, true, otherNode);
    return true;
}



