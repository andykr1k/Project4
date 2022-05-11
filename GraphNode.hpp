#ifndef Project4_GraphNode_hpp
#define Project4_GraphNode_hpp

#include<iostream>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include "systemInterface.hpp"
#include "Token.hpp"
#include "Reader.hpp"
using namespace std;

class GraphNode {

public:
    //Constructors
    GraphNode( string name );

    //Getters
    std::string getName() { return _name; };
    long getTimestamp() { return _timestamp; };
    std::string getCommand() { return _command; };
    bool onPath() { return _onPath; };
    bool wasMade() { return _wasMade; };
    bool isATarget() { return _isATarget; };
    int numDependentNodes() { return _listOfDependentNodes->size(); };
    std::vector<GraphNode *> *dependentNodes() { return _listOfDependentNodes; };

    //Setters
    void setName( std::string name ) { _name = name; };
    void setTimestamp(long ts) { _timestamp = ts; };
    void setCommand(std::string cmnd) { _command = cmnd; };
    void onPath(bool v) { _onPath = v; };
    void wasMade(bool v) { _wasMade = v; };
    void isATarget(bool v) { _isATarget = v; };

    //Functions
    void runCommand(){ executeCommand(cmnd); };
    void addDependentNode(GraphNode *child) { _listOfDependentNodes->push_back(child); };
    void print();

private:
    std::string _name, _command;
    const char *cmnd = _command.c_str();
    long _timestamp;
    std::vector<GraphNode *> *_listOfDependentNodes;

    bool _onPath, _isATarget, _wasMade;
};
#endif
