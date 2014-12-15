/*************************
* Class Expression       *
* TNG033: Lab 3          *
**************************/

#ifndef EXP_H
#define EXP_H

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double EPSILON = 1.0e-5;


class Expression
{
public:
    
    Expression() = default;
    
    //Destructor
    virtual ~Expression() { };
    
    
    //A function, called isRoot, to test whether a given value x is a root of the function f.
    
    bool isRoot (double x) const;
    
    
    //An overloaded operator() to evaluate an expression E, given a value d for variable
    //x, i.e. E(d) returns the value of expression E when x gets the value d.
    
    virtual double operator()(double x) const = 0;
    
    //Copy
    virtual Expression* clone() const = 0;
    
    
    //A stream insertion operator operator<< to display an expression.
    
    friend ostream& operator<<(ostream& os, const Expression& E);
    
    virtual void display(ostream& os) const = 0;
    
};


#endif
