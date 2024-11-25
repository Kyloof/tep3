#include <iostream>
#include <string>
#include "src/AbstractSyntaxTree/AbstractSyntaxTree.h"
#include "src/Command/Command.h"


int main()
{
    std::queue<std::string> strQ;
    AbstractSyntaxTree AST1;
    AbstractSyntaxTree AST2;
    std::string x = "+ ab + 1 - 3 2";
    std::string y = "- ab 1";
    AST1.enter(x);
    AST1.print();
    AST2.enter(y);
    AST2.print();
    AST1.partialSwap(AST2, "-");
    AST1.print();
    AST2.print();

    //Command cmd;
    //cmd.commandLine();

}
