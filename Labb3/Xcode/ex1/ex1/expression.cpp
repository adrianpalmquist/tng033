/*********************************************************
* Class Expression member functions implementation       *
* TNG033: Lab 3                                          *
**********************************************************/

#include "expression.h"


//ADD implementation of the member functions for class Expression



bool Expression::isRoot (double x) const{
    if (fabs(this->operator()(x))<EPSILON)
        return true;
    return false;
}

ostream& operator<<(ostream& os, const Expression& E){
    //os << " Expression operator<< was called " << endl;
    E.display(os);
    return os;
}