#include<iostream>
#include<vector>
#include<string>
#include"ev.h"
using namespace std;

// Store expression and its postfix result
struct ExpressionResult {
    string infixExpression;
    string postfixResult;
};

// Global variables for game state
vector<ExpressionResult> results;
string longestExpression = "";

// Function prototypes
void displayMenu();
void addExpression(Queue& exprQueue, PostFix& postfix);
void processExpression(Queue& exprQueue, PostFix& postfix);
void displayQueue(Queue& exprQueue);
void displayLongestExpression();
void showResults();
void processAll(Queue& exprQueue, PostFix& postfix);
void loadSampleQueue(Queue& exprQueue);

int main()
{
    PostFix p1;
    Queue expressionQueue;
    
    // Setup operators with their associativity and precedence
    p1.setOperator("+", 0, 6);  // Right-associative, precedence 6
    p1.setOperator("-", 0, 6);
    p1.setOperator("*", 0, 5);  // Left-associative, precedence 5
    p1.setOperator("/", 0, 5);
    p1.setOperator("(", 0, 2);
    p1.setOperator(")", 0, 2);
    
    cout << "========================================" << endl;
    cout << "  EXPRESSION EVALUATION GAME SYSTEM" << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    int choice = 0;
    
    while (choice != 8)
    {
        displayMenu();
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear newline from buffer
        
        cout << endl;
        
        switch (choice)
        {
            case 1:
                addExpression(expressionQueue, p1);
                break;
            case 2:
                processExpression(expressionQueue, p1);
                break;
            case 3:
                displayQueue(expressionQueue);
                break;
            case 4:
                displayLongestExpression();
                break;
            case 5:
                showResults();
                break;
            case 6:
                processAll(expressionQueue, p1);
                break;
            case 7:
                loadSampleQueue(expressionQueue);
                break;
            case 8:
                cout << "Thank you for using the Expression Evaluation System!" << endl;
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 8." << endl;
        }
        
        if (choice != 8)
        {
            cout << "\nPress Enter to continue...";
            cin.get();
        }
    }
    
    return 0;
}

void displayMenu()
{
    cout << "\n========================================" << endl;
    cout << "              MAIN MENU" << endl;
    cout << "========================================" << endl;
    cout << "1. Add Expression to Queue" << endl;
    cout << "2. Process Next Expression" << endl;
    cout << "3. Display Queue" << endl;
    cout << "4. Display Longest Expression" << endl;
    cout << "5. Show All Results" << endl;
    cout << "6. Process All Expressions" << endl;
    cout << "7. Load Sample Queue" << endl;
    cout << "8. Exit" << endl;
    cout << "========================================" << endl;
}

void addExpression(Queue& exprQueue, PostFix& postfix)
{
    string expression;
    cout << "Enter arithmetic expression (e.g. a * b + c): ";
    getline(cin, expression);
    
    if (expression.empty())
    {
        cout << "Error: Expression cannot be empty!" << endl;
        return;
    }
    
    // Add to queue
    exprQueue.enqueue(expression);
    cout << "Expression '" << expression << "' added to queue successfully!" << endl;
    
    // Check if this is the longest expression
    if (expression.length() > longestExpression.length())
    {
        longestExpression = expression;
        cout << "★ New longest expression recorded! ★" << endl;
    }
}

void processExpression(Queue& exprQueue, PostFix& postfix)
{
    if (exprQueue.isEmpty())
    {
        cout << "Queue is empty! No expressions to process." << endl;
        return;
    }
    
    // Get the front expression
    string infixExpr = exprQueue.top();
    
    // Convert to postfix
    string postfixResult = postfix.evaluateExpression(infixExpr);
    
    // Store the result
    ExpressionResult result;
    result.infixExpression = infixExpr;
    result.postfixResult = postfixResult;
    results.push_back(result);
    
    // Remove from queue
    exprQueue.dequeue();
    
    cout << "✓ Expression processed successfully!" << endl;
    cout << "Infix:   " << infixExpr << endl;
    cout << "Postfix: " << postfixResult << endl;
}

void displayQueue(Queue& exprQueue)
{
    if (exprQueue.isEmpty())
    {
        cout << "Queue is currently empty." << endl;
        return;
    }
    
    cout << "========================================" << endl;
    cout << "      PENDING EXPRESSIONS QUEUE" << endl;
    cout << "========================================" << endl;
    cout << "Total expressions in queue: " << exprQueue.getsize() << endl;
    cout << "----------------------------------------" << endl;
    exprQueue.display();
    cout << "========================================" << endl;
}

void displayLongestExpression()
{
    if (longestExpression.empty())
    {
        cout << "No expressions have been entered yet." << endl;
        return;
    }
    
    cout << "========================================" << endl;
    cout << "       LONGEST EXPRESSION" << endl;
    cout << "========================================" << endl;
    cout << "Expression: " << longestExpression << endl;
    cout << "Length: " << longestExpression.length() << " characters" << endl;
    cout << "========================================" << endl;
}

void showResults()
{
    if (results.empty())
    {
        cout << "No expressions have been processed yet." << endl;
        return;
    }
    
    cout << "========================================" << endl;
    cout << "       PROCESSED RESULTS" << endl;
    cout << "========================================" << endl;
    cout << "Total processed: " << results.size() << " expression(s)" << endl;
    cout << "========================================" << endl;
    
    for (int i = 0; i < results.size(); i++)
    {
        cout << "\n[" << (i + 1) << "]" << endl;
        cout << "Infix:   " << results[i].infixExpression << endl;
        cout << "Postfix: " << results[i].postfixResult << endl;
        cout << "----------------------------------------" << endl;
    }
}

void processAll(Queue& exprQueue, PostFix& postfix)
{
    if (exprQueue.isEmpty())
    {
        cout << "Queue is empty! No expressions to process." << endl;
        return;
    }
    
    int count = 0;
    cout << "Processing all expressions in queue..." << endl;
    cout << "========================================" << endl;
    
    while (!exprQueue.isEmpty())
    {
        string infixExpr = exprQueue.top();
        string postfixResult = postfix.evaluateExpression(infixExpr);
        
        ExpressionResult result;
        result.infixExpression = infixExpr;
        result.postfixResult = postfixResult;
        results.push_back(result);
        
        exprQueue.dequeue();
        count++;
        
        cout << "[" << count << "] " << infixExpr << " -> " << postfixResult << endl;
    }
    
    cout << "========================================" << endl;
    cout << "Successfully processed " << count << " expression(s)!" << endl;
}

void loadSampleQueue(Queue& exprQueue)
{
    // Sample expressions strictly testing Precedence and Parentheses
    // (No chained operators of the same precedence level like "a + b - c")
    vector<string> sampleExpressions = {
        // 1. Basic Single Operators
        "a + b",            
        "x * y",

        // 2. Strict Precedence (Multiplication/Division before Addition/Subtraction)
        "a + b * c",        // Should do (b * c) first
        "x * y + z",        // Should do (x * y) first
        "m - n / o",        // Should do (n / o) first

        // 3. Parentheses Overriding Precedence
        "( a + b ) * c",    // Parens force (+) before (*)
        "x * ( y + z )",    // Parens force (+) before (*)

        // 4. Nested Parentheses (Explicit ordering)
        "( ( a + b ) * c )", 
        
        // 5. Separated Groups (Safe because * is higher than +)
        "( a + b ) * ( c - d )" // Inner parens done first, then multiply
    };
    
    cout << "Loading 'No-Associativity' test cases..." << endl;
    cout << "========================================" << endl;
    
    for (int i = 0; i < sampleExpressions.size(); i++)
    {
        exprQueue.enqueue(sampleExpressions[i]);
        cout << "[" << (i + 1) << "] " << sampleExpressions[i] << endl;
        
        // Update longest expression if necessary
        if (sampleExpressions[i].length() > longestExpression.length())
        {
            longestExpression = sampleExpressions[i];
        }
    }
    
    cout << "========================================" << endl;
    cout << "✓ Successfully loaded " << sampleExpressions.size() << " sample expressions!" << endl;
    
    if (!longestExpression.empty())
    {
        cout << "★ Longest expression: " << longestExpression << " (" << longestExpression.length() << " chars)" << endl;
    }
}
