cmake_minimum_required(VERSION 3.29)
project(lab3)
include_directories(
        src/Node
        src/NodeTypes/Literal
        src/NodeTypes/Operator
        src/NodeTypes/Variable

)
set(CMAKE_CXX_STANDARD 98)

add_executable(lab3 main.cpp
        src/AbstractSyntaxTree/AbstractSyntaxTree.cpp
        src/AbstractSyntaxTree/AbstractSyntaxTree.h
        src/Node/ANode.cpp
        src/Node/ANode.h
        src/Node/NodeEnum.h
        src/NodeTypes/Literal/Literal.cpp
        src/NodeTypes/Literal/Literal.h
        src/NodeTypes/Operator/Operator.cpp
        src/NodeTypes/Operator/Operator.h
        src/NodeTypes/Variable/Variable.cpp
        src/NodeTypes/Variable/Variable.h)
