/*********************************************************
 * Class Log member functions implementation              *
 * TNG033: Lab 3                                          *
 **********************************************************/

#include "logarithm.h"
#include "polynomial.h"

//ADD implementation of the member functions for class Log


//A default constructor that creates the logarithm 𝑙𝑜𝑔2𝑥
Log::Log(){
    b = 2;
    c1 = 0;
    c2 = 1;
    exp = new Polynomial();
}

//A constructor that given an expression 𝐸, and constants 𝑐1, 𝑐2, and 𝑏 creates a logarithmic expression 𝑐1 + 𝑐2 × 𝑙𝑜𝑔𝑏(𝐸)
Log::Log(const Expression& E, double C1, double C2, int B){
    c1 = C1;
    c2 = C2;
    b = B;
    exp = E.clone();
}

//A copy constructor
Log::Log(const Log& l){
    c1 = l.c1;
    c2 = l.c2;
    b = l.b;
    exp = l.exp;
}

//Destructor
Log::~Log(){
    cout << "Log destructor was called:" << endl;
    cout << *this << endl << endl;
    delete exp;
    c1 = c2 = b = 0;
}

//An assignment operator
const Log& Log::operator=(const Log& l){
    c1 = l.c1;
    c2 = l.c2;
    b = l.b;
    delete exp;
    exp = l.exp;
    
    return *this;
}


double Log::operator()(double x) const{
    double f = c1;
    
    if (b == 2) {
        f += c2 * log2(exp->operator()(x));
    }
    else
        f += c2 * log10(exp->operator()(x));
    
    return f;
}


//Display function
void Log::display(ostream& os) const{
    if (!(fabs(c2)<EPSILON)) {
        if (!(fabs(c1)<EPSILON)) {
            os << c1 << "+";
        }
        os << c2 << "*log_" << b;
        os << "( " <<  *exp << " )" << endl;
    }
    else
        os << "0" << endl;
}
