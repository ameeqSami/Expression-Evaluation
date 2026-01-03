#include "operator.h"

void Operator::setOperatorName(string op)
{
    Opratr = op;
}

void Operator::setAssociativity(bool assoc)
{
    Associativity = assoc;
}

void Operator::setPrecedence(int prec)
{
    Precedence = prec;
}

void Operator::setOperator(string op, bool assoc, int prec)
{
    setOperatorName(op);
    setAssociativity(assoc);
    setPrecedence(prec);
}

string Operator::getOperatorName()
{
    return Opratr;
}

bool Operator::getAssociativity()
{
    return Associativity;
}

int Operator::getPrecedence()
{
    return Precedence;
}

Operator::Operator(string op, bool assoc, int prec)
{
    setOperator(op, assoc, prec);
}

void Operator::displayOperatorInfo()
{
    cout << "Operator: " << getOperatorName() << endl;
    cout << "Associativity: " << (getAssociativity() ? "Right to Left" : "Left to Right") << endl;
    cout << "Precedence: " << getPrecedence() << endl;
}