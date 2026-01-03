#include "node.h"
Node::Node(string d, Node *n)
{
    setData(d);
    next = n;
}

void Node::setData(string d)
{
    data = d; 
}

string Node::getData()
{
    return data;
}

void Node::setNode(string d, Node *n)
{
    setData(d);
    next = n;
}

void Node::display()
{
    cout<<getData()<<endl;
}
