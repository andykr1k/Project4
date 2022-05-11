#ifndef Project4_Token_hpp
#define Project4_Token_hpp

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Token {
public:
    //Constructor
    Token(): _isTab{false}, _isCommand{false}, _isName{false}, _isColon{false}, _eol{false}, _eof{false} {};

    //Getters
    string getCommand() { return _command; }
    string getName() { return _name; }
    bool isEol() { return _eol; }
    bool isEof() { return _eof; }
    bool isName() { return _isName; }
    bool isTab() { return _isTab; }
    bool isCommand() { return _isCommand; }
    bool isColon() { return _isColon; }

    //Setters
    void makeName(string n) { _name = n; _isName = true; }
    void makeCommand(string n) { _command = n; _isCommand = true; }
    void makeTab() { _isTab = true; }
    void makeColon() { _isColon = true; }
    void makeEOF() { _eof = true; }
    void makeEOL() { _eol = true; }

    //Functions
    void print();

private:
    string _command, _name;
    bool _isTab, _isCommand, _isName, _isColon, _eol, _eof;
};


#endif
