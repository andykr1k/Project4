#include <iostream>
#include <cstdlib>
#include "DepGraph.hpp"
#include "systemInterface.hpp"
using namespace std;

int main(int argc, const char *argv[]) {
    if( argc != 2 ) {
        std::cout << "usage: " << argv[0] << " name-of-a-makefile\n";
        exit(1);
    }

    //Read File, Tokenize and Make tree
    DepGraph *make = new DepGraph(argv[1]);

    //Parse tree and make dependency graph
    make->parseDepGraph();

    //Print Makefile
    //make->print();

    //Check to see if is cyclic
    if( make->isCyclic() )  {
        std::cerr << "Input graph has cycles.\n";
        exit(1);
    }

    //Run make based off dependency graph
    make->runMake();

    //Check if commands ran..if not send up-to-date message
    if ( !make->commandRunReturn()){
        std::cout << "make: '" << make->returnTarget()->getName() <<  "' is up to date." << endl;
    }
    return 0;
}
