#include<iostream>
#include"Queue/queue.h"
using namespace std;
main()
{
    Queue q1;
    q1.enqueue('q');
    q1.enqueue('w');
    q1.enqueue('e');
    q1.enqueue('r');
    q1.enqueue('t');
    q1.enqueue('y');
    q1.display();
}