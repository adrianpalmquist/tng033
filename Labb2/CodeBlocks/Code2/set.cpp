#include "set.h"

//Default constructor
Set::Set ()
{
    head = new Node(0,nullptr);
}

//Constructor creating a set
//from n integers in a non-sorted array a
Set::Set (int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        head->next->value = a[n];
    }
}

//copy constructor
Set::Set (const Set &source)
{
   Set();
   *head = *source.head;
}

//Destructor: deallocate all nodes
Set::~Set ()
{
    Node* node = head;
    delete node;
    while(!head->next)
    {
        delete head;
    }
}

//Test if set is empty
bool Set::empty () const
{
    if (!head->next)
        return true;

    return false;
}

//Return number of elements in the set
int Set::cardinality() const
{
    int counter = 0;
    while(!head->next)
        counter++;
    if(counter>0)
        return counter;

    return 0;
}

//Test if x is an element of the set
bool Set::member (int x) const
{
    while(!head->next){
        if(head->value == x)
            return true;
    }
    return false;
}

bool Set:: operator<=(const Set& b) const
{
    int test = 0;

    while(!head->next)
    {
        if(!b.member(head->value))
        {
            return false;
        }

        test = 1;
    }

    if (test == 1)
    {
        return true;
    }

    return false;
}


bool Set:: operator==(const Set& b) const
{
    int test1 = 0;
    int test2 = 0;
    Set node = *this;

    if(node <= b)
        test1 = 1;

    while(!b.head->next)
    {
        if(head->value != b.head->value)
        {
        return false;
        }
        test2 = 1;
    }

    if (test1 == 1 && test2 == 1)
    {
        return true;
    }

    return false;
}

bool Set:: operator<(const Set& b)  const
{
    Set node = *this;
    if(node <= b && !(b <= node))
    {
        return true;
    }

    return false;
}


//Set union
//Repeated values are not allowed
Set Set::operator+ (const Set& b) const
{
    Set node = *this;
    if (node < b)
    {
        while(!node->next)
        {

        }
    }

    return *this; //to be deleted
}

//Set intersection
Set Set::operator* (const Set& b) const
{
    //Add code
   return *this; //to be deleted
}

//Set difference
Set Set::operator- (const Set& b) const
{
    //Add code
    return *this; //to be deleted
}

//set union with set {x}
Set Set::operator+(int x) const
{
    //Add code
    return *this; //to be deleted
}

//set difference with set {x}
Set Set::operator-(int x) const
{
    //Add code
    return *this; //to be deleted
}

//Assignment operator
const Set& Set::operator=(const Set &s)
{
    //Add code
    return *this; //to be deleted
}

ostream& operator<< (ostream& os, const Set& theSet)
{
    //Add code
    return os;
}

