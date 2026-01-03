#include "queue.h"

Queue::Queue()
{
    Head = nullptr;
    Tail = nullptr;
}

Queue::~Queue()
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
        Tail = nullptr;
    }
}

int Queue::getsize()
{
    return count;
}

bool Queue::isEmpty()
{
    return Head == nullptr;
}

void Queue::enqueue(string d)
{
    Node* temp = new Node(d);

    if (Tail)
    {
        Tail->next = temp; 
        Tail = temp;
    }
    else Head = Tail = temp; 
    count++;
    
}

bool Queue::dequeue()
{
    if (Head)
    {
            Node* toDelete = Head;
            Head = Head->next;
            delete toDelete;
            count--;
            return true;
    }
    return false;
}

string Queue::top()
{
    return Head->data;
}

void Queue::display()
{
    if(!Head) return;
 
    int size = count;
    for (int i = 0; i < size; i++)
    {
        cout<<top();
        enqueue(top());
        dequeue();
    }
        

}