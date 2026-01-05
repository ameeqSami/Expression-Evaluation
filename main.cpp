#include<iostream>
#include"ev.h"
#include<vector>
using namespace std;
int main()
{
    PostFix p1;
    p1.setOperator("+", 0, 6);
    p1.setOperator("-", 0, 6);
    p1.setOperator("/", 1, 5);
    p1.setOperator("*", 1, 5);
    p1.setOperator("(", 0, 2);
    p1.setOperator(")", 0, 2);
    
    cout << "Test 1: a + b" << endl;
    cout << "Result: [" << p1.evaluateExpression("a + b") << "]" << endl;
    
    cout << endl << "Test 2: Ali + Zeeshan / a + b * c - d" << endl;
    cout << "Result: [" << p1.evaluateExpression("Ali + Zeeshan / a + b * c - d") << "]" << endl;
    
    return 0;
} 