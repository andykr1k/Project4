#include "DepGraph.hpp"
#include "GraphNode.hpp"

void DepGraph::print(){
    _tree->print();
}

void DepGraph::parseDepGraph(){
    //Making a reader
    Reader *reader = new Reader(_fileToMake);
    //Getting first token
    Token token = reader->getToken();

    //while token is not eof read and parse
    while( !token.isEof() ){
        parseHelper(token, reader);
        token = reader->getToken();
    }

    //Setting first target of depgraph
    firstTarget = _tree->getRoot()->graphNode();
}

void DepGraph::parseHelper(Token token, Reader *reader){
    //First token should be a file name
    if (!token.isName()){
        cout << "Should be a file Name" << endl;
        exit(1);
    }

    //Looks for node if not makes new GraphNode and inserts into the tree
    GraphNode *node = _tree->find(token.getName());
    if (node == nullptr){
        node = new GraphNode(token.getName());
        _tree->insert(node);
    }

    token = reader->getToken();

    //This token should be a colon after the file name
    if(!token.isColon()){
        cout << "Should be a colon" << endl;
        exit(2);
    }

    //Setting that node/filename as a target since a colon was after it
    node->isATarget(true);

    token = reader->getToken();

    //This token should the dependent(s)
    while (!token.isEol()) {
        GraphNode *dependent = _tree->find(token.getName());
        if (dependent == nullptr){
            dependent = new GraphNode(token.getName());
            _tree->insert(dependent);
        }
        node->addDependentNode(dependent);
        token = reader->getToken();
    }

    //This token should be an EOL after the dependent(s)
    if (!token.isEol()){
        cout << "Should be a EOL" << endl;
        exit(5);
    }

    token = reader->getToken();

    //This token should be a tab before the command
    if (!token.isTab()){
        cout << "Should be a Tab" << endl;
        exit(5);
    }

    token = reader->getToken();

    //This token should be commmand after tab
    if (!token.isCommand()){
        cout << "Should be a command" << endl;
        exit(5);
    }
    //Setting command
    node->setCommand(token.getCommand());
}

void DepGraph::runMake(){
    runHelper(firstTarget);
}

void DepGraph::runHelper(GraphNode *node) {
    //Base Cases
    if(node == nullptr || node->wasMade()){
        return;
    }

    //Leaf Node Checker
    if(node->dependentNodes()->size() == 0){
        long depTs;
        //get timestamp
        timestamp(node->getName().c_str(), &depTs);
        //check to see if file exists
        if(depTs == -1){
            cout << node->getName() << ": file not existent - runHelper in DepGraph.cpp: Line 75" << endl;
            exit(11);
        }
        //set timestamp
        node->setTimestamp(depTs);
        return;
    }
    vector<GraphNode*> *dependentNodes = node->dependentNodes();

    //Checking dependencies
    long MaxDepTs = 0;
    for (int i = 0; i < dependentNodes->size(); ++i) {
        //Recursive call
        runHelper(dependentNodes->at(i));
        //Process done node is made
        dependentNodes->at(i)->wasMade(true);
        //setting Max Dependency Time Stamp
        if(dependentNodes->at(i)->getTimestamp() > MaxDepTs){
            MaxDepTs = dependentNodes->at(i)->getTimestamp();
        }
    }

    //checking to see if needs make command
    long targetTs = 0;
    //get timestamp
    timestamp(node->getName().c_str(), &targetTs);
    //Check to execute command
    if(targetTs == -1 || MaxDepTs > targetTs){
        executeCommand(node->getCommand().c_str());
        //Sets true if command has run for status update
        commandHasRun = true;
        //get timestamp
        timestamp(node->getName().c_str(), &targetTs);
    }
    //set timestamp
        node->setTimestamp(targetTs);
    //After all processes node is made
    node->wasMade(true);
}

bool DepGraph::isCyclic(){
    return isCyclicHelper(firstTarget);
}

bool DepGraph::isCyclicHelper(GraphNode *node) {
    //Base Case
    if(node == nullptr){
        return false;
    }
    //Base Case
    if(node->onPath()){
        return true;
    }

    std::vector<GraphNode*> *dependentNodes = node->dependentNodes();
    //Puts node on path
    node->onPath(true);

    //Checks all dependents
    for(int i =0; i < dependentNodes->size();i++){
        //recursive call
        isCyclicHelper(dependentNodes->at(i));
        //if node has been visited it is cyclic
        if(dependentNodes->at(i)->onPath()){
            return true;
        }
    }

    //if node has not been visited before is not cyclic
    node->onPath(false);
    return false;
}

void DepGraph::print(GraphNode *node){
    node->print();
}
