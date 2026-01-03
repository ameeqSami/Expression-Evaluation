#pragma once
#include<iostream>
using namespace std;

class Operator{
    private: 
    string Opratr;
    bool Associativity;
    int Precedence;

    protected: 
    void setOperatorName(string op);
    void setAssociativity(bool assoc);
    void setPrecedence(int prec);
    void setOperator(string op, bool assoc, int prec);
    
    public: 
    string getOperatorName();
    bool getAssociativity();
    int getPrecedence();
    
    Operator(string op = "", bool assoc = 0, int prec = -1);
    void displayOperatorInfo();

};