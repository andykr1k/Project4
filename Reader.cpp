#include "Reader.hpp"

Reader::Reader(string inputFile) {
    //Open Stream for reader
    lastTokenTab = false;
    targetSoon = true;
    inputFileName = inputFile;
    inputStream.open(inputFile, std::ios::in);
}

Token Reader::getToken() {
    //Checks to see if stream is open
    if(!inputStream.is_open()){
        std::cout << "Input stream in Reader::getToken is not open. Terminating...\n";
        exit(1);
    }

    //gets first character
    char c;
    inputStream.get(c);

    //if the state of the reader is last token was a tab make a command
    if (lastTokenTab){
        lastTokenTab = false;
        targetSoon = true;
        string command = "";
        while ( c != '\n'){
            command += c;
            inputStream.get(c);
        }
        Token token;
        token.makeCommand(command);
        return token;
    }

    //skip spaces and empty newlines
    while ( c == ' ' || (targetSoon && c == '\n')){
        inputStream.get(c);
    }

    //if its not a tab then target is not soon
    if ( c != '\t'){
        targetSoon = false;
    }

    //Check character for eof, colon, newline, tab, or file name
    if ( inputStream.eof()){
        Token token;
        token.makeEOF();
        return token;
    } else if ( c == ':'){
        Token token;
        token.makeColon();
        return token;
    }else if ( c == '\n'){
        targetSoon = true;
        Token token;
        token.makeEOL();
        return token;
    } else if ( c == '\t'){
        Token token;
        token.makeTab();
        lastTokenTab = true;
        return token;
    } else {
        string fName;
        fName += c;
        while (inputStream.get(c) && !(c == ' ' || c == ':' || c == '\n')){
            fName += c;
        }
        Token token;
        token.makeName(fName);
        inputStream.putback(c);
        return token;
    }
}