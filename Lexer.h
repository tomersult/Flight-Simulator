
#ifndef EX3_LEXER_H
#define EX3_LEXER_H

#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

class Lexer {
public:
    Lexer(string fileName1);

    void parser();

    vector<string> splitIt(string line);

    vector<string> getVectorList();


private:
    vector<string> lexerVector;
    string fileName;
};


#endif //EX3_LEXER_H