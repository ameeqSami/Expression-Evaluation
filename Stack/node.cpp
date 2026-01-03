#include "node.h"
Node::Node(Operator d, Node *n)
{
    setData(d);
    next = n;
}

void Node::setData(Operator d)
{
    data = d; 
}

Operator Node::getData()
{
    return data;
}

void Node::display()
{
    cout<<getData()<<endl;
}
