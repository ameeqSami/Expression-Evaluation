#pragma once

#include<iostream>
#include"node.h"
using namespace std;

class Queue{
    private: 
    Node* Head;
    Node* Tail;
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
