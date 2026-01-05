#include<iostream>
#include"ev.h"
#include<vector>
using namespace std;

int main()
{
    PostFix p1;
    p1.setOperator("+", 0, 6);  // left-associative, precedence 6 (lower)
    p1.setOperator("-", 0, 6);  // left-associative, precedence 6 (lower)
    p1.setOperator("/", 1, 5);  // right-associative, precedence 5 (higher)
    p1.setOperator("*", 1, 5);  // right-associative, precedence 5 (higher)
    p1.setOperator("(", 0, 2);
    p1.setOperator(")", 0, 2);
    
    // Test simple expressions first
    cout << "Test 1: a + b" << endl;
    cout << "Result: [" << p1.evaluateExpression("a + b") << "]" << endl;
    cout << "Expected: [a b + ]" << endl << endl;
    
    cout << "Test 2: a + b * c" << endl;
    cout << "Result: [" << p1.evaluateExpression("a + b * c") << "]" << endl;
    cout << "Expected: [a b c * + ]" << endl << endl;
    
    cout << "Test 3: a * b + c" << endl;
    cout << "Result: [" << p1.evaluateExpression("a * b + c") << "]" << endl;
    cout << "Expected: [a b * c + ]" << endl << endl;
    
    cout << "Test 4: a + b + c" << endl;
    cout << "Result: [" << p1.evaluateExpression("a + b + c") << "]" << endl;
    cout << "Expected: [a b + c + ]" << endl << endl;
    
    cout << "Test 5: a / b / c" << endl;
    cout << "Result: [" << p1.evaluateExpression("a / b / c") << "]" << endl;
    cout << "Expected (right-assoc): [a b c / / ]" << endl << endl;
    
    return 0;
}
