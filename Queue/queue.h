#pragma once

#include<iostream>
#include"node.h"
using namespace std;

class Queue{
    private: 
    QueueNS::Node* Head;
    QueueNS::Node* Tail;
    int count = 0;

    public: 
    Queue();
    ~Queue();
    
    int getsize();
    bool isEmpty();
    void enqueue(string d);
    bool dequeue();
    string top();
    void display();



};
