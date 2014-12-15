/*********************************************************
* Class Polynomial member functions implementation       *
* TNG033: Lab 3                                          *
**********************************************************/

#include "polynomial.h"
#include <cassert>

//ADD implementation of the member functions for class Polynomial

Polynomial::Polynomial(){
    howMany = 2;
    c = new double[howMany];
    c[0] = 0;
    c[1] = 1;
}


Polynomial::Polynomial(int d, double a[]){
    howMany = d+1;
    c = new double[howMany];
    for (int i = 0; i < howMany; i++) {
        c[i] = a[i];
    }
}


Polynomial::Polynomial(double n){
    howMany = 1;
    c = new double[howMany];
    c[0] = n;
}


Polynomial::~Polynomial(){
    cout << "Polynomial destructor was called:" << endl;
    cout << *this << endl << endl;
    delete [] c;
    //howMany = 0;
}


Polynomial::Polynomial(const Polynomial& p){
    howMany = p.howMany;
    c = new double[howMany];
    for (int i = 0; i < howMany; i++) {
        c[i] = p.c[i];
    }
}


//An assignment operator

const Polynomial& Polynomial::operator=(const Polynomial& p){
    if (this != &p) {
        delete [] c;
        howMany = p.howMany;
        c = new double[howMany];
        for (int i = 0; i < howMany; i++) {
            c[i] = p.c[i];
        }
    }
    return *this;
}


//Addition of two polynomials p+q, where p and q are polynomials

Polynomial const Polynomial::operator+(const Polynomial& p) const{
    Polynomial p1 = *this;
    Polynomial p2 = p;
    Polynomial p3;
    
    int total;
    
    if (p1.howMany > p2.howMany) {
        total = p1.howMany;
    }
    else
        total = p2.howMany;
 
    p3.c = new double[total];
    
    for (int i = 0; i < p1.howMany; i++) {
        p3.c[i] = p1.c[i];
    }
    
    for (int i = 0; i < p2.howMany; i++) {
        p3.c[i] += p2.c[i];
    }
    
    p3.howMany = total;
    
    return p3;
}



//Addition of a polynomial with a real (double) value d, i.e. p+d and d+p, where p is a polynomial

Polynomial operator+(double n, const Polynomial& p){
    Polynomial p1 = p;
    
    p1.c[0] += n;
    
    return p1;
}



//A subscript operator, operator[ ], that can be used to access the value of a polynomial’s coefficient

double& Polynomial::operator[](int n){
    return c[n];
}




double Polynomial::operator()(double x) const{
    double f = 0.0;
    
    for (int i = 0; i < howMany; i++) {
        if (!(fabs(c[i])<EPSILON))
        {
            if (i == 0)
                f = c[i];
            else
                f = f + (c[i] * pow(x, i));
        }
    }
    return f;
}

//Display function
void Polynomial::display(ostream& os) const{
    for (int i = 0; i < howMany; i++) {
        if (!(fabs(c[i])<EPSILON) || i == 0)
        {
            if (i == 0)
                os << fixed << setprecision(2) << c[i];
            else
                os << " + " << c[i] << " * X^" << i;
        }
    }
}