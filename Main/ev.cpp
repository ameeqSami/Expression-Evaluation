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

    // OPTIMIZATION: Use an index 'i' instead of erasing from the vector (which is slow)
    for (int i = 0; i < tokens.size(); i++)
    {
        string token = tokens[i];
        int exprOpr = isOperator(token);

        if (exprOpr == -1) // It is an Operand
        {
            output += token + " ";
        }
        else // It is an Operator
        {
            if (token == "(") {
                stk.push(oprs[exprOpr]);
            }
            else if (token == ")") {
                while (!stk.isEmpty() && stk.top().getOperatorName() != "(") {
                    output += stk.top().getOperatorName() + " ";
                    stk.pop();
                }
                if (!stk.isEmpty()) stk.pop(); // Pop the "("
            }
            else 
            {
                // PRECEDENCE HANDLING (Lower Value = Higher Precedence)
                while (!stk.isEmpty() && stk.top().getOperatorName() != "(")
                {
                    int topPrec = stk.top().getPrecedence();
                    int currPrec = oprs[exprOpr].getPrecedence();
                    bool isRightAssoc = oprs[exprOpr].getAssociativity(); 

                    // POP CONDITION:
                    // 1. Top is STRICTLY STRONGER (Lower number) than Current
                    //    Ex: Top is '*' (5), Current is '+' (6). 5 < 6. Pop '*'.
                    // 2. Precedence is EQUAL, and operator is LEFT Associative
                    //    Ex: Top is '+' (6), Current is '+' (6). Pop top first.
                    
                    if (topPrec < currPrec || (topPrec == currPrec && !isRightAssoc)) 
                    {
                        output += stk.top().getOperatorName() + " ";
                        stk.pop();
                    } 
                    else 
                    {
                        break; // Stop popping if Top is weaker
                    }
                }
                stk.push(oprs[exprOpr]);
            }
        }
    }

    // Pop remaining operators
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