//
// Created by oriel Asraf on 07/11/2019.
//
#ifndef PROJECT_EXPRESSION_H
#define PROJECT_EXPRESSION_H

using namespace std;

/**
 * Expression Interface
 */
class Expression {

public:
/**
 * calculate - calculate
 * @return nothing.
 */
    virtual double calculate() = 0;

    /**
     * disconstructor.
     */
    virtual ~Expression() {}
};

#endif //PROJECT_EXPRESSION_H