/*************************
* Class Log              *
* TNG033: Lab 3          *
**************************/


#ifndef LOG_H
#define LOG_H

#include <iostream>

using namespace std;

#include "expression.h"

class Log : public Expression
{
public:
    //A default constructor that creates the logarithm 𝑙𝑜𝑔2𝑥
    Log();
    
    //A constructor that given an expression 𝐸, and constants 𝑐1, 𝑐2, and 𝑏 creates a logarithmic expression 𝑐1 + 𝑐2 × 𝑙𝑜𝑔𝑏(𝐸)
    Log(const Expression& E, double C1, double C2, int B);
    
    //A copy constructor
    Log(const Log& l);
    
    //Destructor
    ~Log();
    
    //An assignment operator
    const Log& operator=(const Log& l);
    
    double operator()(double x) const;
    
    //Clone expression
    Expression* clone() const{
        return new Log(*this);
    }
    
    void display() const;
    
protected:
    double c1, c2;
    int b;
    Expression* exp;
    
    void display(ostream& os) const;

};

#endif
