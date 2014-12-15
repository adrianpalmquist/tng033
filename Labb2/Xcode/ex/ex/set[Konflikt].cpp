#include "set.h"
#include <cassert>

//Default constructor
Set::Set ()
{
    head = new Node(0,nullptr);
}

//Constructor creating a set
//from n integers in a non-sorted array a
Set::Set (int a[], int n)
{
    //Bubblesort
    int i, j, flag = 1;    // set flag to 1 to start first pass
    int temp;
    int numLength = n;
    for(i = 1; (i <= numLength) && flag; i++)
    {
        flag = 0;
        for (j=0; j < (numLength -1); j++)
        {
            if (a[j+1] < a[j])
            {
                temp = a[j];             // swap elements
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = 1;               // indicates that a swap occurred
            }
        }
    }

    //Insert sorted a[]
        for (int i = n-1; i > -1; i = i-1){
            head = new Node(a[i],head);
        }
     head = new Node(0,head);
}

//copy constructor
Set::Set (const Set &source)
{
    /*
    //Niclas special

    head = new Node(0, nullptr);

    Node* node = source.head->next;
    Node* newNode = head;

    while (node) {
        newNode->next = new Node(node->value,nullptr);
        node = node->next;
        newNode = newNode->next;
    }
     */

}

//Destructor: deallocate all nodes
Set::~Set ()
{
/*
    Node* node = head;
    Node* newNode;

    while (node) {
        newNode = node->next;
        delete node;
        node = newNode;
    }
    */
}

//Test if set is empty
bool Set::empty () const
{
    /*
    Node* node = this->head;

    if (!node->next)
        return true;

     */
    return false;
}

//Return number of elements in the set
int Set::cardinality() const
{
    /*
    Node* node = this->head->next;

    int counter = 0;

    while(node){
        counter++;
        node = node->next;
        cout << "card" << endl;
    }

    return counter;
     */
    return 0;
}

//Test if x is an element of the set
bool Set::member (int x) const
{
    /*
    Node* node = this->head->next;

    while(node){
        if(node->value == x){
            return true;
        }
        node = node->next;
        cout << " member" << endl;
    }
     */
    return false;

}

//Test if R is subset of S
bool Set:: operator<=(const Set& b) const
{
    /*
    Set set = b;
    Node* node = this->head->next;

    int flag = 0;

    while(node)
    {
        if(!(set.member(node->value)))
        {
            return false;
        }

        flag = 1;
        node = node->next;
    }

    if (flag == 1)
    {
        return true;
    }
*/
    return false;

}

//Test if R is subset of S and S is subset of R
bool Set:: operator==(const Set& b) const
{
    /*
    //int test1 = 0;
    //int test2 = 0;

    Set S1 = *this;
    Set S2 = b;

    if(S1 <= S2 && S2 <= S1)
        return true;

        //test1 = 1;

    /*while(!b.head->next)
    {
        if(head->value != b.head->value)
        {
        return false;
        }
        test2 = 1;
    }
    if (test1 == 1)
    {
        return true;
    }
     */

    return false;
}


//Test if R is proper subset of S
bool Set:: operator<(const Set& b)  const
{
    /*
    Set S1 = *this;
    Set S2 = b;

    if(S1 <= S2 && !(S2 <= S1))
    {
        return true;
    }
*/
    return false;

}


//Set union
//Repeated values are not allowed
Set Set::operator+ (const Set& b) const
{
    /*
    Set S1 = *this;
    Set S2 = b;
    Set S3;

    Node* node1 = S1.head->next;
    Node* node2 = S2.head->next;
    Node* node3 = S3.head;


    //Merge S1 with S2
    while (node1 && node2)
    {
        if (node1->value < node2->value && node1->value > node3->value)
        {
            node3->next = new Node(node1->value, nullptr);
            node1 = node1->next;
        }
        else if (node2->value < node1->value && node2->value > node3->value)
        {
            node3->next = new Node(node2->value, nullptr);
            node2 = node2->next;
        }
        else if (node1->value > node3->value || node2->value > node3->value)
        {
            node3->next = new Node(node1->value, nullptr);
            node1 = node1->next;
            node2 = node2->next;
        }
        else{
            node1 = node1->next;
            node2 = node2->next;
        }

        node3 = node3->next;

    }

    //copy any remaining values from S1 to S3
    while(node1)
    {
        node3->next = new Node(node1->value, nullptr);
        node1 = node1->next;
    }

    //copy any remaining values from S2 to S3
    while(node2)
    {
        node3->next = new Node(node2->value, nullptr);
        node2 = node2->next;
    }

    return S3;
     */
    return *this;
}

//Set intersection
Set Set::operator* (const Set& b) const
{
    /*
    Set S1 = *this;
    Set S2 = b;
    Set S3;

    Node* node1 = S1.head->next;
    Node* node3 = S3.head;

    while (node1) {
    if (S2.member(node1->value)) {
        node3->next = new Node(node1->value, nullptr);
        node3 = node3->next;
    }
        node1 = node1->next;
    }

   return S3;
     */
    return *this;
}

//Set difference
Set Set::operator- (const Set& b) const
{
    /*
    Set S1 = *this;
    Set S2 = b;
    Set S3;

    Node* node1 = S1.head->next;
    Node* node3 = S3.head;

    while (node1) {
        if (!S2.member(node1->value)) {
            node3->next = new Node(node1->value, nullptr);
            node3 = node3->next;
        }
        node1 = node1->next;
    }


    return S3;
     */
    return *this;
}

//set union with set {x}
Set Set::operator+(int x) const
{

    /*
    Set S1 = *this;
    Set S2(S1);
    Node* node = S2.head->next;

    if (!S2.member(x)) {
        while (node->next) {
            node = node->next;
        }
        node->next = new Node(x,nullptr);
    }
    return S2;
     */
    return *this;
}

//set difference with set {x}
Set Set::operator-(int x) const
{
    /*
    Set S1 = *this;
    Set S2(S1);
    Node* node = S2.head->next;
    Node* temp;


    if (S2.member(x)) {
        while (node->next) {
            cout << "Testing if " << x << " = " << node->value << endl;
            if (node->value == x) {
                temp = node;
                node = node->next;
                //delete temp;
            }
            else
            node = node->next;
        }
    }


    return S2;
     */
    return *this;
}

//Assignment operator
const Set& Set::operator=(const Set &s)
{
    /*
    delete head;
    head = new Node(0, nullptr);

    Node* node = s.head->next;
    Node* newNode = head;

    while (node) {
        newNode->next = new Node(node->value,nullptr);
        node = node->next;
        newNode = newNode->next;
    }
    */
    return *this; //to be deleted
}

ostream& operator<< (ostream& os, const Set& theSet)
{

    if (!theSet.head->next) {
        os << "Set is empty!" << endl;
        return os;
    }

    else {
        Node* temp = theSet.head->next;
        os << "{ ";
        while(temp){
            os << temp->value << " ";
            temp = temp->next;
        }
        os << "}" << endl;
        return os;
    }

    return os;
}

