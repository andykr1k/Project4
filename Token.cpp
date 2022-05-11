#include <string>
#include <iostream>
#include <fstream>
#include "Token.hpp"
using namespace std;

void Token::print(){
    if (isColon()) {
        cout << ":" << endl;
    } else if (isName()){
        cout << getName() << endl;
    } else if (isTab()){
        cout << "Tab" << endl;
    } else if (isCommand()){
        cout << getCommand() << endl;
    } else if (isEol()) {
        cout << "EOL" << endl;
    } else if (isEof()) {
        cout << "EOF" << endl;
    } else {
        cout << "No Token";
    }
}