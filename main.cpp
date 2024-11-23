#include <iostream>

#include "src/AbstractSyntaxTree/AbstractSyntaxTree.h"
#include "src/Command/Command.h"

int main()
{
    /*AbstractSyntaxTree AST1;
    AbstractSyntaxTree AST2;
    std::string x = "+ 1 + 1 - 3 2 1 2";
    std::string y = "- a ";
    AST1.enter(x);
    AST1.print();
    AST2.enter(y);
    AbstractSyntaxTree AST3 = AST1 + AST2;
    AST3.print();*/

    Command cmd;
    cmd.commandLine();

}
