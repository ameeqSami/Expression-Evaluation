#pragma once

#include<iostream>
using namespace std;

class Node{
    public: 
    char data; 
    Node* next;

    Node(string d = "", Node* n = nullptr);
    void setData(string d);
    string getData();
    void setNode(string d = "", Node* n = nullptr);
    void display();
};