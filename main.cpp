#include <iostream>
#include "ex1.h"
#include "Expression.h"
#include "Lexer.h"
#include "DefineVarCommand.h"
#include <map>
#include "Command.h"
#include "Data.h"
#include <unordered_map>
#include "Data.h"
#include "whileLoopCommand.h"
#include <iterator>
#include "printCommand.h"
#include "ifCommand.h"
#include <queue>

using namespace std;

queue<string> queue1 ;


int main(int argc ,char* argv[]) {
    // runing the program.
    string fileName = argv[1];
    Lexer lexer1(fileName);
    lexer1.parser();
    vector<string> myVectorList = lexer1.getVectorList();
    int index = 0;
    // runing the parser with the vector with all the info.
    parserClass *parserClass1 = new parserClass(myVectorList, index);
    parserClass1->parse();
}
