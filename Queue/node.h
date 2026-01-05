#pragma once

#include<iostream>
using namespace std;

namespace QueueNS {
    class Node{
        public: 
        string data; 
        Node* next;

        Node(string d = "", Node* n = nullptr);
        void setData(string d);
        string getData();
        void setNode(string d = "", Node* n = nullptr);
        void display();
    };
}