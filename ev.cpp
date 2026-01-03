#include "ev.h"

void PostFix::incrementOperatorCount()
{
    totalOperators++;
}

int PostFix::getOperatorCount()
{
    return totalOperators;
}

void PostFix::addOprator(Operator op)
{
    oprs.push_back(op);
    incrementOperatorCount();   
}

PostFix::PostFix()
{
    totalOperators = 0;
}

string PostFix::evaluateExpression(Queue expr)
{
    string output; 
    Stack stk;
    while(!expr.isEmpty()){
        int exprOpr  = isOperator(expr.top());
        if (exprOpr != -1){
            output += expr.top();
        }
        else{
            if(!stk.isEmpty()) stk.push(oprs[exprOpr]);
            else if(stk.top().getPrecedence() >= oprs[exprOpr].getPrecedence() && )
            {
                
            }
            
        }
    }
    
}

void PostFix::setOperator(string op, bool assoc, int prec)
{
    addOprator(Operator(op, assoc, prec));
}

void PostFix::displayAllOperators()
{
    for(int i = 0; i < getOperatorCount(); i++)
    {
        oprs[i].displayOperatorInfo();
    }
}

int PostFix::isOperator(string a)
{
    for (int i = 0; i < oprs.size(); i++)
    {
        if (a == oprs[i])
            return i;
    }
    return -1;
}
