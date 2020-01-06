#include "Lexer.h"

Lexer::Lexer(string fileName1) {
    this->fileName = fileName1;
}

void Lexer::parser() {
    /**
     * the purposr of this class is to go over the text
     * and devide all the orders i am given from the txt.
     * by parser the text in to a vector i can go over the text in other class
     * and make them execute.
     * we are trying to find a key word from the txt and by that parser the line.
     * when we find our key word we push in a new vector the words in the order will
     * help us next in the program. then we go back to the main loop in the class
     * and enterd the words we got after the line been parserd and enterd them in
     * to the main vector!
     */
    ifstream inFile;
    inFile.open(this->fileName);
    string line;
    if (inFile.good()) {
        // taking a line from the text and parser her.
        while (getline(inFile, line)) {
            vector<string> vector2 = splitIt(line);
            int i;
            for (i = 0; i < vector2.size(); i++) {
                this->lexerVector.push_back(vector2[i]);
            }
        }
    }
    inFile.close();
}

vector<string> Lexer::splitIt(string line) {

    vector<string> splitVector;
    vector<string> nextSplit;
    int countSpaces = 0;
    string tempLine = "";
    //removing spaces from a start of a line.
    for (int j = 0; j < line.length(); ++j) {
        if (line[j] == ' ') {
            countSpaces++;
        } else {
            break;
        }
    }
    line.erase(0, countSpaces);
    string tab = "\t";
    //removing tabing
    if (line.find(tab) == 0) {
        line.erase(remove(line.begin(), line.end(), '\t'), line.end());
    }
    tempLine = line;
    // if i see the word var in the line parser it.
    if (line.find("var ") == 0) {
        string space = " ";
        size_t pos = 0;
        string token;
        while ((pos = tempLine.find(space)) != string::npos) {
            token = tempLine.substr(0, pos);
            splitVector.push_back(token);
            tempLine.erase(0, pos + space.length());
        }
        int position = tempLine.find("(");
        tempLine.erase(0, position + 1);
        position = tempLine.find(")");
        if (line.find("=") != string::npos) {
            token = tempLine.substr(0, position - 2);
        } else {
            token = tempLine.substr(1, position - 2);
        }
        splitVector.push_back(token);
        return splitVector;
        // if i see the word openDataServer in the line parser it.
    } else if (line.find("openDataServer") == 0) {
        string token;
        int pos = line.find("(");
        int zero = 0;
        token = tempLine.substr(0, pos);
        splitVector.push_back(token);
        tempLine.erase(0, pos + 1);
        pos = tempLine.find(")");
        token = tempLine.substr(0, pos);
        splitVector.push_back(token);
        return splitVector;
        // if i see the word connectControlClient in the line parser it.
    } else if (line.find("connectControlClient") == 0) {
        string token;
        int pos = tempLine.find("(");
        token = tempLine.substr(0, pos);
        splitVector.push_back(token);
        tempLine.erase(0, pos + 1);
        pos = tempLine.find(")");
        token = tempLine.substr(0, pos);
        pos = token.find(",");
        splitVector.push_back(token.substr(1, pos - 2));
        splitVector.push_back(token.substr(pos + 1, token.length()));
        return splitVector;
        // if i see the word Sleep in the line parser it.
    } else if (line.find("Sleep") == 0) {
        string token;
        int pos = line.find("(");
        int zero = 0;
        token = tempLine.substr(0, pos);
        splitVector.push_back(token);
        tempLine.erase(0, pos + 1);
        pos = tempLine.find(")");
        token = tempLine.substr(0, pos);
        splitVector.push_back(token);
        return splitVector;
        // if i see the word Print in the line parser it.
    } else if (line.find("Print") == 0) {
        string token;
        int size = 0;
        int pos = line.find("(");
        token = tempLine.substr(0, pos);
        splitVector.push_back(token);
        tempLine.erase(0, pos + 1);
        size = tempLine.length();
        int wehreIsIt = 0;
        for (int i = 0; i < size; ++i) {
            if (tempLine[i] == ')') {
                wehreIsIt = i;
            }
        }
        token = tempLine.substr(0, wehreIsIt);
        splitVector.push_back(token);
        return splitVector;
        // if i see the word while in the line parser it.
    } else if (line.find("while") == 0) {
        string space = " ";
        size_t pos = 0;
        string token;
        while ((pos = tempLine.find(space)) != string::npos) {
            token = tempLine.substr(0, pos);
            splitVector.push_back(token);
            tempLine.erase(0, pos + space.length());
        }
        splitVector.push_back(tempLine);
        return splitVector;
// if i see the word if in the line parser it.
    } else if (line.find("if") == 0) {
        string space = " ";
        size_t pos = 0;
        string token;
        while ((pos = tempLine.find(space)) != string::npos) {
            token = tempLine.substr(0, pos);
            splitVector.push_back(token);
            tempLine.erase(0, pos + space.length());
        }
        splitVector.push_back(tempLine);
        return splitVector;
// if i see the operator '}' in the line parser it.
    } else if (tempLine.find("}") == 0) {
        splitVector.push_back(tempLine);
        return splitVector;
        // else thats mean its not a command its asigmment or stuff like that.
    } else {
        string token;
        string eqale = "=";
        int pos = tempLine.find("=");
        token = tempLine.substr(0, pos);
        splitVector.push_back(token);
        tempLine.erase(0, pos + 1);
        splitVector.push_back(eqale);
        tempLine.erase(remove(tempLine.begin(), tempLine.end(), ' '), tempLine.end());
        splitVector.push_back(tempLine);
        return splitVector;
    }
}

vector<string> Lexer::getVectorList() {
    return this->lexerVector;
}


