#ifndef Project4_Reader_hpp
#define Project4_Reader_hpp

#include <string>
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "Token.hpp"
using namespace std;

class Reader {
public:
    //Constructor
    Reader(string inputFile);

    //Getters
    Token getToken();
    bool isLastTokenTab() { return lastTokenTab; }
    bool isTargetSoon() { return targetSoon; }

private:
    string inputFileName;
    fstream inputStream;
    bool lastTokenTab;
    bool targetSoon;
};


#endif
