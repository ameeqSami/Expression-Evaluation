#include "ev.h"

void PostFix::incrementOperatorCount(){
    totalOperators++;
}

int PostFix::getOperatorCount(){
    return totalOperators;
}

void PostFix::addOprator(Operator op){
    oprs.push_back(op);
    incrementOperatorCount();
}

PostFix::PostFix(){
    totalOperators = 0;
}

vector<string> PostFix::stringToVector(string expr){
    vector<string> tokens;
    for (int i = 0; i < expr.length(); i++)
    {
        if (isspace(expr[i]))
            continue;

        if (i + 1 < expr.length())
        {
            string twoChar = expr.substr(i, 2);
            if (findOperator(twoChar))
            {
                tokens.push_back(twoChar);
                i++;
                continue;
            }
        }

        if (findOperator(string(1, expr[i])))
        {
            tokens.push_back(string(1, expr[i]));
            continue;
        }

        string word;
        while (i < expr.length() && !isspace(expr[i]))
        {
            word += expr[i];
            i++;
        }

        tokens.push_back(word);
        i--;
    }

    return tokens;
}

string PostFix::evaluateExpression(string expr)
{

    vector<string> tokens = stringToVector(expr);
    string output;
    Stack stk;

    while (!tokens.empty())
    {

        int exprOpr = isOperator(tokens.front());

        if (exprOpr == -1)  // It's an operand (NOT an operator)
        {
            output += tokens.front() + " ";  // FIXED: Added space
        }
        else
        {
            if (tokens.front() == "("){
                stk.push(oprs[exprOpr]);
            }
            else if (tokens.front() == ")")
            {
                while (!stk.isEmpty() && stk.top().getOperatorName() != "(")
                {
                    output += stk.top().getOperatorName() + " ";
                    stk.pop();
                }
                stk.pop(); //  removing opening braket from stack
            }
            else if (stk.isEmpty()){
                stk.push(oprs[exprOpr]);}

            else if (stk.top().getOperatorName() == "(" ){
                stk.push(oprs[exprOpr]);}

            else if (stk.top().getPrecedence() > oprs[exprOpr].getPrecedence())
                    {
                stk.push(oprs[exprOpr]);
                    }
            else if (stk.top().getPrecedence() == oprs[exprOpr].getPrecedence() && !oprs[exprOpr].getAssociativity())
                        {
                stk.push(oprs[exprOpr]);
                    }
                    else
                    {
                while (!stk.isEmpty() && stk.top().getOperatorName() != "(" &&  stk.top().getPrecedence() <= oprs[exprOpr].getPrecedence())
                {
                    if (stk.top().getPrecedence() == oprs[exprOpr].getPrecedence() && (oprs[exprOpr].getAssociativity()))
                        break;
                    output += stk.top().getOperatorName() + " ";
                    stk.pop();
                }
                stk.push(oprs[exprOpr]);
            }
        }
        tokens.erase(tokens.begin());
    }

    // Pop remaining operators from stack
    while (!stk.isEmpty())
    {
        output += stk.top().getOperatorName() + " ";
        stk.pop();
    }

    return output;
}

void PostFix::setOperator(string op, bool assoc, int prec){
    addOprator(Operator(op, assoc, prec));
}

void PostFix::displayAllOperators(){
    for (int i = 0; i < getOperatorCount(); i++)
    {
        oprs[i].displayOperatorInfo();
    }
}

int PostFix::isOperator(string a){
    for (int i = 0; i < oprs.size(); i++)
    {
        if (a == oprs[i].getOperatorName())
            return i;
    }
    return -1;
}

int PostFix::findOperator(string a){
    for (int i = 0; i < oprs.size(); i++)
    {
        if (a == oprs[i].getOperatorName())
            return 1;
    }
    return 0;
}