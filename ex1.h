//
// Created by tomer on 12/11/2019.
//

#ifndef EX1_EX1_H
#define EX1_EX1_H

#include "Expression.h"

#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <iterator>
#include <string.h>
#include <iostream>
#include <cstring>
#include "ex1.h"
#include "Expression.h"
#include <vector>
#include <map>
#include <sstream>
#include <stack>
#include <queue>

using namespace std;
/*class Expression {

public:
    virtual double calculate()=0;

    virtual ~Expression() {}

};*/

class Value : public Expression {
protected:
    double value;
public:
    Value(double value);

    double calculate();

    virtual ~Value() {}

};

class BinaryOperator : public Expression{
protected:
    Expression* right;
    Expression* left;

public:
    BinaryOperator (Expression *right ,Expression *left);
    double calculate ();

    ~BinaryOperator(){delete (left);delete(right);}//!!!!!!!!!!!!!!!!!!!!!!
};

class Plus : public BinaryOperator{
public:
    Plus (Expression *left_ , Expression *right_);
    double calculate();
    virtual ~Plus(){}
};

class Minus : public BinaryOperator{
public:
    Minus (Expression *left_ , Expression *right_);
    double calculate();
    virtual ~Minus(){}
};

class Mul : public BinaryOperator{
public:
    Mul (Expression *left_ , Expression *right_);
    double calculate();
    virtual ~Mul(){}
};

class Div : public BinaryOperator{
public:
    Div (Expression *left_ , Expression *right_);
    double calculate();
    virtual ~Div(){}
};

class Variable : public Expression {
protected:
    string name ;
    double value ;

public:
    Variable (string name , double value);
    double calculate();
    Variable &operator++();
    Variable &operator++(int);
    Variable &operator--();
    Variable &operator--(int);
    Variable &operator+=(double value);
    Variable &operator-=(double value);
};

class UnaryOperator : public Expression{
protected:
    Expression* expression;
public:
    UnaryOperator (Expression *exp);
    double calculate ();
    ~UnaryOperator(){delete expression;}

};

class UPlus :public UnaryOperator {
public:
    UPlus(Expression *expression1);
    double calculate();
    virtual ~UPlus();
};

class UMinus :public UnaryOperator {
public:
    UMinus(Expression *expression1);
    double calculate();
    virtual ~UMinus();
};


class Interpreter{
protected:
    std::map<string,string> map ;
    stack<double> firstStack ;
    stack<string> secondStack ;
    stack<string> thirdStack ;
public:
    Expression* interpret (string str);
    std::map<string, string> &setVariables(string str);
    double applyOp (double a , double b , string op);
    int precedence (string op);
};


#endif //EX1_EX1_H
