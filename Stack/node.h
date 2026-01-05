#include<iostream>
#include"../Operator/operator.h"
using namespace std;

namespace StackNS {
    class Node{
        public: 
        Operator data; 
        Node* next;

        Node(Operator d = Operator(), Node* n = nullptr);
        void setData(Operator d);
        Operator getData();
        void display();

    };
}