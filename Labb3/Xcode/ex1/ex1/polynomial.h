/*************************
* Class Polynomial       *
* TNG033: Lab 3          *
**************************/

#ifndef POL_H
#define POL_H

#include <iostream>

using namespace std;

#include "expression.h"


class Polynomial : public Expression
{
public:
    Expression* clone() const{
        return new Polynomial(*this);
    }
    
    Polynomial();
    
    
    //A constructor that creates a polynomial from an array of doubles
    
    Polynomial(int d, double a[]);
    
    
    //A conversion constructor to convert a real constant into a polynomial
    
    Polynomial(double n);
    
    
    //A copy constructor
    
    Polynomial(const Polynomial& p);
    
    //Destructor
    ~Polynomial();
    
    
    //An assignment operator
    
    const Polynomial& operator=(const Polynomial& p);
    
    
    //Addition of two polynomials p+q, where p and q are polynomials
    
    Polynomial const operator+(const Polynomial& p) const;
    
    
    
    //Addition of a polynomial with a real (double) value d, i.e. p+d and d+p, where p is a polynomial
    
    friend Polynomial operator+(double n, const Polynomial& p);
    
    
    
    //A subscript operator, operator[ ], that can be used to access the value of a polynomial’s coefficient
    
    double& operator[](int n);
    
    
    
    double operator()(double x) const;
    
    
    
protected:
    double* c;
    int howMany;
    
    void display(ostream& os) const;
};


#endif
