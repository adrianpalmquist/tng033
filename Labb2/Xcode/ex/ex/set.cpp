#include "set.h"
#include <cassert>
#include <NEW>

//Default constructor
Set::Set ()
{
    head = new Node(0,nullptr);
}

//Insert
void Set::insert (int x){
    if(empty()){ // Check if set is empty
        head->next = head->insert(x); // If it is, insert x after dummy node
    }
    else {
        Node* temp = head;
        while (temp->next){ // tittar en framåt
            if(x > temp->next->value)
            { // mindre gå vidare
                temp = temp->next;
            }
            else if	(x < temp->next->value)
            { // lägger till
                temp->insert(x);			 // insert function från node
                return;
            }
            else if(x == temp->next->value)
            { // om det redan finns
                return;
            }
        }
        
        temp = temp->insert(x);
    }
    
}

//Constructor creating a set
//from n integers in a non-sorted array a
Set::Set (int a[], int n)
{
    head = new Node(0,nullptr);
    
    for (int i = 0; i < n; i++)
    {
        insert(a[i]);
    }
}

//copy constructor
Set::Set (const Set &source)
{
    
    //Niclas special
    
    head = new Node(0, nullptr);
    
    Node* node = source.head->next;
    Node* newNode = head;
    
    while (node) {
        newNode->next = new Node(node->value,nullptr);
        node = node->next;
        newNode = newNode->next;
    }
   
}

//Destructor: deallocate all nodes
Set::~Set ()
{
    while (head) {
        Node* temp = head->next;
        delete head;
        head = temp;
    }
    delete head;
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
    Node* node = this->head->next;
    
    int counter = 0;
    
    while(node){
        counter++;
        node = node->next;
    }
    
    return counter;
}

//Test if x is an element of the set
bool Set::member (int x) const
{
    Node* node = this->head->next;
    
    while(node){
        if(node->value == x){
            return true;
        }
        node = node->next;
    }
    return false;
    
}

//Test if R is subset of S
bool Set:: operator<=(const Set& b) const
{
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
    
    if (flag)
    {
        return true;
    }
    return false;
}

//Test if R is subset of S and S is subset of R
bool Set:: operator==(const Set& b) const
{
    Set S1 = *this;
    Set S2 = b;
    
    if(S1 <= S2 && S2 <= S1)
        return true;
    
    return false;
}


//Test if R is proper subset of S
bool Set:: operator<(const Set& b)  const
{
    Set S1 = *this;
    Set S2 = b;
    
    if(S1 <= S2 && !(S2 <= S1))
    {
        return true;
    }
    return false;
}


//Set union
//Repeated values are not allowed
Set Set::operator+ (const Set& b) const
{
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
}

//Set intersection
Set Set::operator* (const Set& b) const
{
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
}

//Set difference
Set Set::operator- (const Set& b) const
{
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
}

//set union with set {x}
Set Set::operator+(int x) const
{
    Set S1 = *this;
    Set S2(S1);
    Node* node = S2.head->next;
    Node* first = S2.head;
    
    if (!S2.member(x)) {
        while (node) {
            if (!node->next) {
                node->next = new Node(x,nullptr);
                return S2;
            }
            else if (node->value > x) {
                first->next = new Node(x,first->next);
                return S2;
            }
            else if (node->next->value > x){
                node->next = new Node(x, node->next);
                return S2;
            }
            node = node->next;
        }
    }
    return S2;
}

//set difference with set {x}
Set Set::operator-(int x) const
{
    Set S1 = *this;
    Set S2(S1);
    Node* node = S2.head->next;
    Node* first = S2.head;
    Node* before = node;
    
    if (S2.member(x)) {
        while (node) {
            if (!node->next) {
                before->next = nullptr;
                return S2;
            }
            if (node->value == x) {
                first->next = first->next->next;
                return S2;
            }
            else
                before = node;
            node = node->next;
        }
    }
    
    return S2;
}

//Assignment operator
const Set& Set::operator=(const Set &s)
{
    delete head;
    head = new Node(0, nullptr);
    
    Node* node = s.head->next;
    Node* newNode = head;
    
    while (node) {
        newNode->next = new Node(node->value,nullptr);
        node = node->next;
        newNode = newNode->next;
    }
    return *this;
}

ostream& operator<< (ostream& os, const Set& theSet)
{
    
    if (theSet.empty()) {
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

