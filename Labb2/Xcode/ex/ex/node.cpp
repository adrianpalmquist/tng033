#include <cassert>
#include "node.h"

Node::Node (int nodeVal, Node *nextPtr)
 : value (nodeVal), next (nextPtr)
{
    //cout << "Constructor Node" << std::endl;
}

// Insert x into new node
Node* Node::insert (int x)
{
    next = new Node (x, next);
    assert(next != nullptr);
    return next;
}