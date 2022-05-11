#include "GraphNode.hpp"

GraphNode::GraphNode( std::string name ){
    _name = name;
    _command = "";
    cmnd = "";
    _timestamp = -1;
    _listOfDependentNodes = {new vector<GraphNode *>};
    _onPath = false;
    _isATarget = false;
    _wasMade = false;
}

void GraphNode::print(){
    //Printing target: dep dep dep \n \t command \n
    cout << _name;
    cout << ":";
    cout << " ";
    for (int i = 0; i < numDependentNodes(); i++){
        cout << _listOfDependentNodes->at(i)->_name << " ";
    }
    cout << endl;
    cout << "\t";
    cout << _command << endl;
};