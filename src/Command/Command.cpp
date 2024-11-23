//
// Created by janku on 20.11.2024.
//

#include "Command.h"

#include <algorithm>
#include <iostream>
#include <sstream>

Command::Command() {}


void Command::commandLine() {
    std::string line;
    std::cout << "Welcome, everything is ok\n";
    std::cout << "Enter command, for more info type 'help'\n";

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, line);

        std::istringstream iss(line);
        std::string command;
        iss >> command;
        std::string arguments;
        std::getline(iss, arguments);
        //delete the first spaces from args
        arguments.erase(arguments.begin(), std::find_if(arguments.begin(), arguments.end(), std::bind1st(std::not_equal_to<char>(), ' ')));


        if (command == "help") {
            helpCommand();
        } else if (command == "enter") {
            if (arguments.empty()) {
                std::cout << "no arguments entered. Please try again." << "\n";
                continue;
            }
            enterCommand(arguments);
        } else if (command == "join") {
            if (arguments.empty()) {
                std::cout << "no arguments entered. Please try again." << "\n";
                continue;
            }
            joinCommand(arguments);
        } else if (command == "print") {
            printCommand();
        } else if (command == "comp") {
            compCommand(arguments);
        } else if (command == "vars") {
            varsCommand();
        } else if (command == "exit") {
            break;
        } else {
            std::cout << "Wrong value entered! Please try again.\n";
        }
    }
}

void Command::helpCommand() {
    std::cout << "Available commands:\n"
              << "help  - Show this help message\n"
              << "enter - Enter values (e.g., 'enter + 1 - 2 3')\n"
              << "join  - Join tree\n"
              << "print - Print tree\n"
              << "comp  - compile <var1> <var2> ...\n"
              << "vars  - Show variables\n"
              << "exit  - Exit the program\n";
}

void Command::enterCommand(const std::string& formula) {
    this->AST.enter(formula);
}

void Command::joinCommand(const std::string& formula) {
    this->AST.join(formula);
}

void Command::printCommand() const {
    this->AST.print();
}

void Command::varsCommand() {
    this->AST.vars();
}

void Command::compCommand(const std::string& formula) const {
    std::cout << this->AST.comp(formula) << "\n";
}





