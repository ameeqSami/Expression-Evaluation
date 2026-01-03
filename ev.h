#include<iostream>
#include<vector>
#include"Stack/stack.h"
#include"Queue/queue.h"
#include"Operator/operator.h"

class PostFix{
    private:
    vector<Operator> oprs;
    int totalOperators;

    protected: 
    void incrementOperatorCount();
    int getOperatorCount();
    void addOprator(Operator op);

    public:
    PostFix();
    string evaluateExpression(Queue expr);
    void setOperator(string op, bool assoc, int prec);
    void displayAllOperators();
    int isOperator(string a);
    
}


