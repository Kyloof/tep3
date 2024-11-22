#include <iostream>

#include "src/AbstractSyntaxTree/AbstractSyntaxTree.h"

int main()
{
    AbstractSyntaxTree AST1;
    AbstractSyntaxTree AST2;
    std::string x = "+ 1 + 1 - 3 2";
    std::string y = "- a + a b";
    AST1.enter(x);
    AST2.enter(y);
    AbstractSyntaxTree AST3 = AST1 + AST2;
    AST3.print();
}
