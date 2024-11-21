#include <iostream>

#include "src/AbstractSyntaxTree/AbstractSyntaxTree.h"

int main()
{
    AbstractSyntaxTree AST;
    std::string x = "sin";
    std::string y = "- a + a b";
    AST.enter(x);
    //AST.join(x);
    AST.print();
    AST.vars();
    std::cout<<AST.comp("");

}
