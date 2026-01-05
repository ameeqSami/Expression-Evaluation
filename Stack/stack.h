#include<iostream>
#include"node.h"
#include"../Operator/operator.h"
using namespace std;

class Stack{
    private: 
    StackNS::Node* Head;
    int size;


    public: 
    Stack();
    ~Stack();
    
    bool isEmpty();
    void push(Operator d);
    bool pop();
    Operator top();
    int Stacksize();
    void display();



};
