//
// Created by oriel on 17/12/2019.
//

#include "printCommand.h"

int printCommand::execute(vector<string> myVector, int index) {
    int find = 0;
    double caculate = 0;
    map<string, Data> first = this->mapsSingeltonClass1.getFirstMapUser();
    map<string, Data> secoend = this->mapsSingeltonClass1.getSecoendMapOut();
    /**
     * checking which kind of print it is.
     * if we find '"' in the the index+1 in the vector- that's mean
     * we are printing a string.
     */
    if ((find = myVector[index + 1].find("\"")) != string::npos) {
        // delete all the " from the string.
        string pri = myVector[index + 1];
        pri.erase(pri.begin() + find);
        find = pri.find("\"");
        pri.erase(pri.begin() + find, pri.begin() + pri.size());
        string temp = pri;
        int length = pri.length();
        char pri1[length + 1];
        // check if we see print(done) to finish the program.
        if (strcmp(pri1, "done") == 0) {
            this->mapsSingeltonClass1.setCheckIfDone(false);
        }
        //printing the string.
        std::cout << pri << '\n';
    } else {
        /**
         * if we are not seeing a " thats we are need ti print some
         * equation or number or just a variable.
         * first we are deleting unnecessery spaces.
         */
        myVector[index + 1].erase(remove(myVector[index + 1].begin(),
                                         myVector[index + 1].end(), ' '),
                                  myVector[index + 1].end());
        string whatToPrint = myVector[index + 1];
        // interpret with our ex1 interpret function.
        Expression *expression = nullptr;
        try {
            expression = this->mapsSingeltonClass1.getInterpreter1()->interpret(whatToPrint);
            caculate = expression->calculate();
            delete expression;

        } catch (const char *e) {
            if (expression != nullptr) {
                delete expression;
            }
        }
        //printing..
        cout << caculate << endl;
    }
    return 2;
}


