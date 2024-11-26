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

//Constructors
AbstractSyntaxTree::AbstractSyntaxTree() : root(0), inputNode(root){}

AbstractSyntaxTree::AbstractSyntaxTree(const AbstractSyntaxTree &other) {
    root = NULL;
    inputNode = NULL;
    if (other.root != NULL) {
        std::string* formula = new std::string;
        this->enter(other.root->getFormula(*formula));
        delete formula;
    }
}


AbstractSyntaxTree::~AbstractSyntaxTree() {
    if (root != 0 && root->getParent()==0) {
        deleteTree();
    }
}

//Operators
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


//Functions
INode* AbstractSyntaxTree::createNode(const std::string& formula, bool isNumber) {
    if (isNumber) return new Literal(formula);
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
    varsSet.insert(formula);
    return new Variable(formula);
}

bool AbstractSyntaxTree::addFormula(const std::string& formula, bool isNumber) {
    bool inputBool = false;
    INode* newNode = createNode(formula, isNumber);

    if (root == NULL) {
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
        //tree is already filled up cuz inputNode == root
        if (inputNode->getParent() == 0) {
            return false;
        }
        inputNode = inputNode->getParent();
    }
    return false;
}

void AbstractSyntaxTree::deleteTree() {
    if (root != NULL) {
        delete root;
        root = NULL;
        inputNode = NULL;
    }
    this->varsSet.clear();
}


std::string AbstractSyntaxTree::fixTree() {
    std::string str;
    if (root == 0) {
        str += "The tree is empty... \n";
        return str;
    }
    bool hadToFix = false;

    //fix children
    while(inputNode!=root) {
        while(inputNode->inputChild(new Literal(1), false, NULL)) hadToFix = true;
        inputNode = inputNode->getParent();
    }

    //fix root
    while (inputNode->inputChild(new Literal(1), false, NULL)) {
        hadToFix = true;
    }

    if (hadToFix) {
        str += "fixed formula: \n";
        root->getFormula(str);
        return str;
    }
    return str;
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

    double returnValue = root->evaluate(varsMap);
    std::ostringstream oss;
    oss << returnValue;
    std::string str = oss.str();
    return str;
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
            enter(formula);
        }
    }
    else {
        *this = other;
    }

}

std::string AbstractSyntaxTree::enter(const std::string &formula) {
    deleteTree();
    std::string message;
    std::string currentFormula;
    bool isNumber = true;
    for (int i = 0; i <= formula.size(); i++) {
        if (formula[i] == ' ' || i == formula.size()  && !currentFormula.empty()){
            const bool result = addFormula(currentFormula, isNumber);
            if (!result) {
                message += "removed: ";
                for (int j = i - 1; j <= formula.size(); j++) {
                    message += formula[j];
                }
                message += "\n";
                return message;
            }
            currentFormula = "";
            isNumber = true;
        }
        else {
            if (!std::isdigit(formula[i])) isNumber = false;
            currentFormula += formula[i];
        }

    }
    message += fixTree();
    return message;
}


std::string AbstractSyntaxTree::vars() {
    std::ostringstream oss;
    std::copy(
        varsSet.begin(),
        varsSet.end(),
        std::ostream_iterator<std::string>(oss, " ")
    );
    return oss.str();
}

std::string AbstractSyntaxTree::returnFormula() const {
    if (root == NULL) return "tree is empty \n";
    std::string str;
    str += "printing tree... \n";
    root->getFormula(str);
    str += "\n";
    return str;
}

INode* AbstractSyntaxTree::searchTokenBFS(const std::string& token) const {
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



