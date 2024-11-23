//
// Created by janku on 20.11.2024.
//

#ifndef COMMAND_H
#define COMMAND_H
#include <vector>

#include "../AbstractSyntaxTree/AbstractSyntaxTree.h"


class Command {

public:
    Command();
    void commandLine();


private:
    void enterCommand(const std::string& formula);
    void printCommand() const;
    void joinCommand(const std::string& formula);
    static void helpCommand();
    void compCommand(const std::string& formula) const;
    void varsCommand();

    AbstractSyntaxTree AST;
};



#endif //COMMAND_H
