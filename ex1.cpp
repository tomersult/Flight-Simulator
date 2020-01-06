//
// Created by tomer on 12/11/2019.
//
#include <stdio.h>
#include "ex1.h"
#include <string>
#include <string.h>
#include <sstream>
#include <vector>

using namespace std;

Value::Value (double _value){
    value = _value;
}

double Value::calculate() {
    return this->value;
}


BinaryOperator::BinaryOperator (Expression *_left ,Expression *_right){
    this->right = _right;
    this->left = _left;
}

double BinaryOperator::calculate() {
    return this->calculate();
}

/*BinaryOperator::~BinaryOperator() {
    delete (this->right);
    delete (this->left);
}*/

Plus::Plus (Expression *left_ ,Expression *right_):BinaryOperator(left_,right_){}

double Plus::calculate (){
    return this->left->calculate() + this->right->calculate();
}

Minus::Minus (Expression *left_ ,Expression *right_):BinaryOperator(left_,right_){}

double Minus::calculate (){
    return this->left->calculate() - this->right->calculate();
}

Mul::Mul (Expression *left_ ,Expression *right_):BinaryOperator(left_,right_){}

double Mul::calculate (){
    return this->left->calculate() * this->right->calculate();
}

Div::Div (Expression *left_ ,Expression *right_):BinaryOperator(left_,right_){}

double Div::calculate (){
    if (this->right->calculate() == 0 ){
        throw ("division by zero");
    }
    return this->left->calculate() / this->right->calculate();
}

Variable::Variable(string name, double value) {
    this->value = value;
    this->name = name;
}

double Variable::calculate() {
    return this->value;
}

Variable& Variable::operator++() {
    this->value = this->value+1;
    return *this;
}

Variable& Variable::operator++(int val) {
    this->value = this->value +1 ;
    return *this;
}

Variable& Variable::operator--() {
    this->value = this->value-1;
    return *this;
}

Variable& Variable::operator--(int val) {
    this->value = this->value -1 ;
    return *this;
}

Variable& Variable::operator+=(double value) {
    this->value = this->value + value;
    return *this;
}

Variable& Variable::operator-=(double value) {
    this->value = this->value - value;
    return *this;
}

UnaryOperator::UnaryOperator(Expression *exp) {
    this->expression = exp;
}

double UnaryOperator::calculate() {
    return this->expression->calculate();
}

UPlus::UPlus(Expression *expression1) : UnaryOperator(expression1) {}
double UPlus::calculate() {
    return this->expression->calculate();
}

UPlus::~UPlus() {}

UMinus::UMinus(Expression *expression1) : UnaryOperator(expression1) {}
double UMinus::calculate() {
    return -this->expression->calculate() ;
}

UMinus::~UMinus() {}

/*Interpreter::Interpreter(Interpreter *interpret) {
    this->Interpreter = interpret ;
}*/

map<string,string>& Interpreter::setVariables(string str) {
    int length = str.length();
    char *semicolon = ";";
    char str1[length];
    string temp(1, str[length-1]);
    strcpy(str1, temp.c_str());

/*    if (strcmp(str1,semicolon)!=0){
        throw std::invalid_argument("bad input !");
    }*/
    char str4[length + 1] ;
    strcpy(str4,str.c_str());
    string c1;
    string c2;
    double num ;
    char * spliter ;
    string str5 ;
    vector<string> v ;
    char check ;
    spliter = strtok(str4,";");
    while (spliter != NULL){
        while (spliter) {
            v.push_back(spliter);
            spliter = strtok(NULL,";");
            //if (spliter[0] == )
        }
        for(int i = 0 ; i <v.size(); i++){
            int temp = v[i].find("=");
            c1 = v[i].substr(0,temp);
            for(int j = 0 ; j < c1.length() ; j++){
                check = c1[j];
                if ((check >= 48 && check <= 57)||(check >= 65 && check <= 90)||
                    (check >= 97 && check <= 122)||(check==95)){}
                else{
                    throw ("illegal variable assignment!");
                }
                if (c1[0]>=48 && c1[0]<=57){
                    throw ("illegal variable assignment!");
                }
            }
            c2 = v[i].substr(temp+1,v[i].length() -1 );
            for(int j = 0 ; j < c2.length() ; j++){
                check = c2[j];
                if ((check >=48 && check<=57)||(check == 46)||(check == 45)||check == 'e'){}
                else{
                    throw ("illegal variable assignment!");
                }

            }

            std::map<string,string>::iterator checkIfExists = this->map.find(c1);
            if (checkIfExists != this->map.end()) {
                checkIfExists->second = c2;
            } else {
                this->map.insert(pair<string, string>(c1, c2));
            }
        }
    }
    return this->map;
}

double Interpreter::applyOp(double num1, double num2, string op) {
    char* plus = "+";
    char* minus = "-";
    char* mul = "*";
    char* div = "/";

    char op1[1];
    op.copy(op1,1,0);

    if (strcmp(op1,div)==0 && num2 ==0 ){
        throw ("can't divide by zero !");
    }

    if (strcmp(op1,plus)== 0){
        return num1 + num2 ;
    }

    else if (strcmp(op1,minus)== 0){
        return num1 - num2 ;
    }
    else if (strcmp(op1,mul)== 0){
        return num1 * num2 ;
    }
    else if (strcmp(op1,div)== 0){
        return num1 / num2 ;
    }
}

int Interpreter::precedence(string op) {
    char* plus = "+";
    char* minus = "-";
    char* mul = "*";
    char* div = "/";
    char* sulmit = "#";
    char* dollar = "$";

    char op1[1];
    op.copy(op1,1,0);

    if(strcmp(op1,plus) == 0 || strcmp(op1,minus) == 0 ){
        return 2 ;
    }
    if(strcmp(op1,mul) == 0 || strcmp(op1,div) == 0 ){
        return 3 ;
    }
    if(strcmp(op1,dollar) == 0 || strcmp(op1,sulmit) == 0 ){
        return 1 ;
    }
    return 0;
}

Expression* Interpreter::interpret(string str) {
    int i ;
    char* pLeft = "(";
    char* pRight = ")";
    char* plus = "+";
    char* minus = "-";
    char* mul = "*";
    char* div = "/";
    char*dot = ".";
    char* sulmit1 = "#";
    char* dollar1 = "$";
    if (str[0] == '-' && str[1]!= '(' && (str[1]<48 || str[1]>57)){
        int index = 0;
        for (int i = 2 ; i <str.size() ; i++){
            if (str[i] !='(' && str[i] !=')' && str[i] !='-' && str[i] !='+' && str[i] !='*' && str[i] !='/' && str[i] !='.'){
                index++;
            }
        }
        string temp1 = str.substr(0,index);
        string temp2 = str.substr(index , str.size() - index);
        str = "(" + temp1 + ")" + temp2 ;
    }
    if (str[0] == '-' && (str[1]>=48 && str[1]<=57)){
        int index = 2 ;
        for (int i = 2 ; i <str.size() ; i++){
            if ((str[i]>=48 &&str[i]<=57)||str[i] =='.' ){
                index++;
            }
        }
        string temp1 = str.substr(0,index);
        string temp2 = str.substr(index , str.size() - index);
        str = "(" + temp1 + ")" + temp2 ;
    }
    str = "(" + str + ")";


    for (i=0 ; i<str.size() ; i++) {
        int k ;
        int countLeft = 0 ;
        int countRight = 0 ;
        for (k=0 ; k<=str.size() ; k++) {
            string temp6(1,str[k]);
            int length6 = temp6.length();
            char temp7[length6 + 1];
            strcpy(temp7, temp6.c_str());

            if (strcmp(temp7, pLeft) == 0){
                countLeft++;
            }
            if (strcmp(temp7, pRight) == 0){
                countRight++;
            }
        }
        if (countLeft!=countRight){
            throw ("illegal math expression");
        }
        string temp(1, str[i]);
        string tempNext (1 , str[i+1]);
        string tempNextNext(1,str[i+2]);
        int length = temp.length();
        char temp1[length + 1];
        strcpy(temp1, temp.c_str());
        int count = 0;
        string temp2;

        char tempPrev[1];
        if(i>=1) {
            str.copy(tempPrev,1,i-1);

        }else{
            tempPrev == "^";
        }

        int f;
        for (f = 0 ; f < str.size() ; f++){
            string temp(1, str[f]);
            string tempNext (1 , str[f+1]);
            string tempNextNext(1,str[f+2]);
            int length = temp.length();
            char temp1[length + 1];
            strcpy(temp1, temp.c_str());
            int lengthNext = tempNext.length();
            int lengthNextNext = tempNextNext.length();
            char tempNext1[lengthNext + 1];
            char tempNextNext1[lengthNextNext + 1];
            strcpy(tempNext1, tempNext.c_str());
            strcpy(tempNextNext1,tempNextNext.c_str());
            if ((strcmp(tempNext1, plus) == 0 || strcmp(tempNext1, minus) == 0 ||strcmp(tempNext1, mul) == 0
                 || strcmp(tempNext1, div) == 0 )){
                if(strcmp(tempNextNext1, plus) == 0 || strcmp(tempNextNext1, minus) == 0
                   ||strcmp(tempNextNext1, mul) == 0 || strcmp(tempNextNext1, div) == 0 ) {
                    throw ("illegal math expression");
                }
            }
        }

        int lengthNext = tempNext.length();
        int lengthNextNext = tempNextNext.length();
        char tempNext1[lengthNext + 1];
        char tempNextNext1[lengthNextNext + 1];
        int j = 1;
        char temp3Next[1];

        if (strcmp(temp1, pLeft) != 0 && strcmp(temp1, plus) != 0 && strcmp(temp1, minus) != 0 &&
            strcmp(temp1, mul) != 0 && strcmp(temp1, div) != 0 && strcmp(temp1, pRight) != 0) {
            while (strcmp(temp1, pLeft) != 0 && strcmp(temp1, plus) != 0 && strcmp(temp1, minus) != 0 &&
                   strcmp(temp1, mul) != 0 && strcmp(temp1, div) != 0 && strcmp(temp1, pRight) != 0) {
                count++;
                temp2 = str.substr(i, count);
                string temp(1, str[i+j]);
                strcpy(temp1, temp.c_str());
                j++;
            }
            i += count -1 ;
        } else {
            temp2 = str.substr(i, 1);
        }
        strcpy(tempNext1, tempNext.c_str());
        strcpy(tempNextNext1,tempNextNext.c_str());
        length = temp2.length();
        char temp3[length];
        strcpy(temp3, temp2.c_str());

        if ((strcmp(temp3, plus) == 0 || strcmp(temp3, minus) == 0 ||strcmp(temp3, mul) == 0
             || strcmp(temp3, div) == 0 )  ){
            if(strcmp(tempNext1, plus) == 0 || strcmp(tempNext1, minus) == 0
               ||strcmp(tempNext1, mul) == 0 || strcmp(tempNext1, div) == 0 ) {
                throw ("illegal math expression");
            }
        }

        if ((strcmp(tempNext1, plus) == 0 || strcmp(tempNext1, minus) == 0 ||strcmp(tempNext1, mul) == 0
             || strcmp(tempNext1, div) == 0 )){
            if(strcmp(tempNextNext1, plus) == 0 || strcmp(tempNextNext1, minus) == 0
               ||strcmp(tempNextNext1, mul) == 0 || strcmp(tempNextNext1, div) == 0 ) {
                throw ("illegal math expression");
            }
        }

        int y = strcmp(temp3,minus);
        if (y==0){
            if (tempPrev[0]==pLeft[0]) {
                temp2 = "#";
                strcpy(temp3, temp2.c_str());
            }
            if ((strcmp(tempNext1,pLeft)==0)&&(tempPrev[0]<48)&&(tempPrev[0]>57)) {
                temp2 = "#";
                strcpy(temp3, temp2.c_str());
            }
        }

        if (strcmp(temp3,plus)==0){
            if(strcmp(tempPrev,pLeft)==0){
                temp2 = "$" ;
                strcpy(temp3, temp2.c_str());
            }
            if(strcmp(tempNext1,pLeft)==0){
                temp2 = "$" ;
                strcpy(temp3, temp2.c_str());
            }
        }



        if ((strcmp(temp3, pLeft)==0)){
            if(strcmp(tempNext1, mul) == 0 || strcmp(tempNext1, div) == 0 ) {
                throw ("illegal math expression");
            }
        }

        if ((strcmp(temp3, pLeft)==0)){
            if(strcmp(tempNext1, plus) == 0 || strcmp(tempNext1, minus) == 0
               ||strcmp(tempNext1, mul) == 0 || strcmp(tempNext1, div) == 0 ) {
                if ((strcmp(tempNextNext1, pRight)==0)) {
                    throw ("illegal math expression");
                }
            }
        }
        if(strcmp(temp3, plus) == 0 || strcmp(temp3, minus) == 0
           ||strcmp(temp3, mul) == 0 || strcmp(temp3, div) == 0 ) {
            if ((strcmp(tempNext1, pLeft)==0)){
                if ((strcmp(tempNextNext1, pRight)==0)) {
                    throw ("illegal math expression");
                }
            }
        }

        if(strcmp(temp3,dot)==0&&strcmp(tempNext1,dot)==0){
            throw ("illegal math expression");
        }
        if(strcmp(temp3,pRight)==0&&strcmp(tempNext1,pLeft)==0){
            throw ("illegal math expression");
        }

        //a opening brace
        if (strcmp(temp3,sulmit1)==0){
            this->secondStack.push(temp3);
        }

        else if (strcmp(temp3,dollar1)==0){
            this->secondStack.push(temp3);
        }

        else if (strcmp(temp3,pLeft)==0){
            this->secondStack.push(temp3);
        }
            //a number or a varible
        else if (strcmp(temp3, pLeft) != 0 && strcmp(temp3, plus) != 0 && strcmp(temp3, minus) != 0 &&
                 strcmp(temp3, mul) != 0 && strcmp(temp3, div) != 0 && strcmp(temp3, pRight) != 0){
            auto itNum1 = this->map.find(temp3);
            double num1;
            if (itNum1 == this->map.end()){
                num1 = stod(temp3);
            }else{
                num1 = stod(itNum1->second);
            }
            this->firstStack.push(num1);
        }
            //a closing brace
        else if (strcmp(temp3,pRight)==0){
            char opTop[1];

            this->secondStack.top().copy(opTop,1,0);
            int g = strcmp(opTop,pLeft);
            while (!this->secondStack.empty() && opTop[0]!=pLeft[0]){
                this->secondStack.pop();


                char opSecond[2] = " " ;
                string top;
                if(!this->secondStack.empty()) {
                    top = this->secondStack.top();
                    strcpy(opSecond, top.c_str());
                }

                if (precedence(opTop)==1){
                    if (opTop[0] == sulmit1[0]) {
                        double val = this->firstStack.top();
                        this->firstStack.pop();
                        val = -val;
                        this->firstStack.push(val);
                        break;
                    }
                }

                double val2 = this->firstStack.top();
                this->firstStack.pop();
                double val1 = this->firstStack.top();
                this->firstStack.pop();
                this->firstStack.push(applyOp(val1,val2,opTop));

                if (precedence(opSecond)==1){
                    if (strcmp(opSecond,sulmit1)==0){
                        val1 = -val1;
                    }
                    if (strcmp(opSecond,dollar1)==0){}
                }

                if (precedence(opSecond)==1){
                    this->secondStack.pop();
                }

                this->secondStack.top().copy(opTop,1,0);

                if (strcmp(opTop,pLeft)){
                    break;
                }
            }

            if(!this->secondStack.empty()){
                this->secondStack.pop();
                if(!this->secondStack.empty()) {
                    this->secondStack.top().copy(opTop, 1, 0);
                    if (opTop[0] == sulmit1[0]) {
                        double val = this->firstStack.top();
                        this->firstStack.pop();
                        val = -val;
                        this->firstStack.push(val);
                        this->secondStack.pop();
                    }
                    if (opTop[0] == dollar1[0]){
                        double val1 = this->firstStack.top();
                        this->firstStack.pop();
                        double val2 = this->firstStack.top();
                        this->firstStack.pop();
                        this->firstStack.push(applyOp(val1,val2,plus));
                        this->secondStack.pop();

                    }
                }
            }
        }
            //an operator
        else {
            while(!this->secondStack.empty() && precedence(this->secondStack.top())>=precedence(temp3)){
                double val2 = this->firstStack.top();
                this->firstStack.pop();
                double val1 = this->firstStack.top();
                this->firstStack.pop();

                string op = this->secondStack.top();
                this->secondStack.pop();

                this->firstStack.push(applyOp(val1,val2,op));
            }
            this->secondStack.push(temp3);
        }
    }

    while (!this->secondStack.empty()){
        double val2 = this->firstStack.top();
        this->firstStack.pop();
        double val1 = this->firstStack.top();
        this->firstStack.pop();

        string op = this->secondStack.top();
        this->secondStack.pop();

        this->firstStack.push(applyOp(val1,val2,op));
    }

    Expression *exp ;
    exp = new Value(this->firstStack.top());
    return exp;
}
