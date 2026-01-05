#include<iostream>
#include"ev.h"
#include<vector>
using namespace std;

int main()
{
    PostFix p1;
    // Current settings:
    // + and - : precedence 6 (lower), right-associative (0)
    // * and / : precedence 5 (higher), left-associative (1)
    p1.setOperator("+", 0, 6);
    p1.setOperator("-", 0, 6);
    p1.setOperator("/", 1, 5);
    p1.setOperator("*", 1, 5);
    p1.setOperator("(", 0, 2);
    p1.setOperator(")", 0, 2);
    
    cout << "=== COMPREHENSIVE TESTS ===" << endl << endl;
    
    cout << "Test 1: a + b" << endl;
    cout << "Result: [" << p1.evaluateExpression("a + b") << "]" << endl << endl;
    
    cout << "Test 2: a + b * c (precedence test)" << endl;
    cout << "Result: [" << p1.evaluateExpression("a + b * c") << "]" << endl << endl;
    
    cout << "Test 3: a * b + c (precedence test)" << endl;
    cout << "Result: [" << p1.evaluateExpression("a * b + c") << "]" << endl << endl;
    
    cout << "Test 4: a + b + c (right-associative +)" << endl;
    cout << "Result: [" << p1.evaluateExpression("a + b + c") << "]" << endl;
    cout << "Meaning: a + (b + c)" << endl << endl;
    
    cout << "Test 5: a - b - c (right-associative -)" << endl;
    cout << "Result: [" << p1.evaluateExpression("a - b - c") << "]" << endl;
    cout << "Meaning: a - (b - c)" << endl << endl;
    
    cout << "Test 6: a * b * c (left-associative *)" << endl;
    cout << "Result: [" << p1.evaluateExpression("a * b * c") << "]" << endl;
    cout << "Meaning: (a * b) * c" << endl << endl;
    
    cout << "Test 7: a / b / c (left-associative /)" << endl;
    cout << "Result: [" << p1.evaluateExpression("a / b / c") << "]" << endl;
    cout << "Meaning: (a / b) / c" << endl << endl;
    
    cout << "Test 8: ( a + b ) * c (parentheses test)" << endl;
    cout << "Result: [" << p1.evaluateExpression("( a + b ) * c") << "]" << endl << endl;
    
    cout << "Test 9: a * ( b + c ) (parentheses test)" << endl;
    cout << "Result: [" << p1.evaluateExpression("a * ( b + c )") << "]" << endl << endl;
    
    cout << "Test 10: Ali + Zeeshan / a + b * c - d (complex expression)" << endl;
    cout << "Result: [" << p1.evaluateExpression("Ali + Zeeshan / a + b * c - d") << "]" << endl << endl;
    
    cout << "Test 11: ( a + b ) * ( c - d )" << endl;
    cout << "Result: [" << p1.evaluateExpression("( a + b ) * ( c - d )") << "]" << endl << endl;
    
    cout << "Test 12: a + b * c + d" << endl;
    cout << "Result: [" << p1.evaluateExpression("a + b * c + d") << "]" << endl << endl;
    
    return 0;
}
