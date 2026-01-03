#include "stack.h"

Stack::Stack()
{
    Head = nullptr;
    size = 0;
}

Stack::~Stack()
{
    if(Head){
        Node* hopper = Head;
        while (hopper)
        {
            Node* temp = hopper;
            hopper = hopper->next;
            delete temp;
        }
        Head = nullptr;
    }
}

bool Stack::isEmpty()
{
    return Head == nullptr;
}

void Stack::push(Operator d)
{
    Node* temp = new Node(d);
    if (Head)
    {
        temp->next = Head;
        Head = temp;

    }
    else    Head = temp;
    size++;


}

bool Stack::pop()
{
    if (Head)
    {
            Node* toDelete = Head;
            Head = Head->next;
            delete toDelete;
            size--;
            return true;
    }
    return false;
}

Operator Stack::top()
{

    return Head->getData();
}

int Stack::Stacksize()
{
    return size;
}

void Stack::display()
{
    Stack temp;
    while (Stacksize())
    {
        cout<<top()<<endl;
        temp.push(top());
        pop();
    }
    while(temp.Stacksize())
    {
        push(temp.top());
        temp.pop();
    }

}