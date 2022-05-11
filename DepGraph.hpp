#ifndef Project4_DepGraph_hpp
#define Project4_DepGraph_hpp
#include <iostream>
#include <cstring>
#include "Token.hpp"
#include "Reader.hpp"
#include "MakeTree.hpp"
#include "GraphNode.hpp"

class DepGraph {
public:
    //Constructor
    DepGraph( std::string name ): _fileToMake{name}, _targetToMake{""}, firstTarget{nullptr}, _tree{new MakeTree()} {};

    //Functions
    void print();
    void print(GraphNode *node);
    void parseDepGraph();
    void runMake();
    bool isCyclic();
    bool commandRunReturn(){return commandHasRun;}
    GraphNode *returnTarget() {return firstTarget;}

private:
    void runHelper(GraphNode *);
    bool isCyclicHelper(GraphNode *node);
    void parseHelper(Token token, Reader *reader);

    std::string _fileToMake, _targetToMake;
    GraphNode *firstTarget;
    MakeTree *_tree;

    bool commandHasRun = false;
};

#endif
