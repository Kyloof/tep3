#include <iostream>
#include <string>
#include "src/AbstractSyntaxTree/AbstractSyntaxTree.h"
#include "src/Command/Command.h"


int main()
{
    AbstractSyntaxTree AST1;
    AbstractSyntaxTree AST2;
    std::string x = "+ ab + 1 - 3 2";
    std::string y = "- ab 1";
    AST1.enter(y);
    AST2.enter(x);
    std::cout<<AST1.returnFormula();
    std::cout<<AST2.returnFormula();
    AST1.partialSwap(AST2, "-");
    std::cout<<AST1.returnFormula();
    std::cout<<AST2.returnFormula();



    Command cmd;
    cmd.commandLine();

}
