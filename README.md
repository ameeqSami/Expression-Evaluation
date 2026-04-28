# Expression Evaluation Game System 🎮

A comprehensive C++ menu-driven system for managing and evaluating arithmetic expressions. This program queues expressions, converts them from Infix to Postfix notation, tracks the longest expression, and stores all results.

## ✨ Features

- **Queue-Based Processing**: FIFO (First In, First Out) expression management
- **Infix to Postfix Conversion**: Automatic conversion using the Shunting Yard algorithm
- **Longest Expression Tracking**: Automatically identifies and displays the longest expression
- **Results History**: Stores and displays all processed expressions
- **Sample Data Loading**: Quick testing with 8 predefined expressions
- **Interactive Menu System**: User-friendly interface with 8 options
- **Batch Processing**: Process all queued expressions at once

## 🎯 Menu Options

1. **Add Expression to Queue** - Manually enter arithmetic expressions
2. **Process Next Expression** - Dequeue and convert one expression
3. **Display Queue** - View all pending expressions
4. **Display Longest Expression** - See the longest expression entered
5. **Show All Results** - View all processed expressions with their postfix results
6. **Process All Expressions** - Batch process entire queue
7. **Load Sample Queue** - Load 8 predefined sample expressions
8. **Exit** - Quit the program

## 🚀 Getting Started

### Prerequisites

- C++ compiler (g++, MinGW, or similar)
- C++11 or later

### Compilation

Navigate to the `Main` directory and compile with all dependencies:

```bash
cd Main
g++ ev.cpp ../Queue/queue.cpp ../Queue/node.cpp ../Stack/stack.cpp ../Stack/node.cpp ../Operator/operator.cpp -o run.exe -I..
```

### Running the Program

```bash
./comprehensive_test.exe
```

## 📖 How It Works

### Infix to Postfix Conversion

The program uses the **Shunting Yard Algorithm** to convert infix expressions to postfix notation:

**Examples:**
- `a + b` → `a b +`
- `x * y + z` → `x y * z +`
- `( a + b / c ) - f` → `a b c / + f -`
- `( p + q ) * ( r - s )` → `p q + r s - *`

### Operator Precedence

- **Multiplication (`*`) and Division (`/`)**: Precedence 5, Left-associative
- **Addition (`+`) and Subtraction (`-`)**: Precedence 6, Right-associative
- **Parentheses `( )`**: Highest priority for grouping

## 💡 Usage Example

```
========================================
  EXPRESSION EVALUATION GAME SYSTEM
========================================

========================================
              MAIN MENU
========================================
1. Add Expression to Queue
2. Process Next Expression
3. Display Queue
4. Display Longest Expression
5. Show All Results
6. Process All Expressions
7. Load Sample Queue
8. Exit
========================================

Enter your choice: 7

Loading sample expressions into queue...
========================================
[1] a + b
[2] x * y + z
[3] ( a + b / c ) - f
[4] m - n * o
[5] ( p + q ) * ( r - s )
[6] a + b * c - d / e
[7] ( ( x + y ) * z )
[8] alpha + beta - gamma
========================================
✓ Successfully loaded 8 sample expressions!
★ Longest expression: alpha + beta - gamma (23 chars)
```

## 🏗️ Project Structure

```
Expression-Evaluation/
├── Main/
│   ├── comprehensive_test.cpp  # Main menu-driven program
│   ├── ev.cpp                   # Expression evaluation implementation
│   └── ev.h                     # Expression evaluation header
├── Queue/
│   ├── queue.cpp                # Queue implementation
│   ├── queue.h                  # Queue header
│   └── node.cpp                 # Queue node implementation
├── Stack/
│   ├── stack.cpp                # Stack implementation
│   ├── stack.h                  # Stack header
│   └── node.cpp                 # Stack node implementation
├── Operator/
│   ├── operator.cpp             # Operator class implementation
│   └── operator.h               # Operator class header
└── README.md                    # This file
```

## 🐛 Bug Fixes

### Critical Queue Display Bug (Fixed)

**Problem**: After processing all expressions, newly added expressions were not visible when displaying the queue.

**Root Cause**: The `dequeue()` function did not reset the `Tail` pointer to `nullptr` when removing the last element, leaving a dangling pointer.

**Solution**: Added a check to reset `Tail = nullptr` when `Head` becomes `nullptr` after dequeuing the last item.

```cpp
if (Head == nullptr)
    Tail = nullptr;
```

## 🔧 Technical Details

### Data Structures

- **Stack**: Used for the Shunting Yard algorithm during infix to postfix conversion
- **Queue**: FIFO structure for managing incoming expressions
- **Vector**: Stores expression results and operator definitions

### Key Classes

- **`PostFix`**: Handles expression tokenization and infix-to-postfix conversion
- **`Queue`**: Implements FIFO queue for expression management
- **`Stack`**: Implements LIFO stack for algorithm processing
- **`Operator`**: Stores operator properties (symbol, precedence, associativity)
- **`ExpressionResult`**: Stores infix and postfix expression pairs

## 🎓 Educational Value

This project demonstrates:
- Data structure implementation (Queue, Stack)
- Algorithm implementation (Shunting Yard Algorithm)
- Object-oriented programming in C++
- Menu-driven program design
- Expression parsing and tokenization
- Operator precedence and associativity handling

## 📝 Sample Expressions Included

1. `a + b` - Simple addition
2. `x * y + z` - Precedence test
3. `( a + b / c ) - f` - Parentheses with division
4. `m - n * o` - Multiplication precedence
5. `( p + q ) * ( r - s )` - Multiple parentheses
6. `a + b * c - d / e` - Complex precedence
7. `( ( x + y ) * z )` - Nested parentheses
8. `alpha + beta - gamma` - Variables with names

## 🤝 Contributing

Contributions are welcome! Feel free to:
- Report bugs
- Suggest new features
- Submit pull requests

## 📄 License

This project is open source and available for educational purposes.

## 👨‍💻 Author

Created as a comprehensive data structures and algorithms project demonstrating queue management, stack-based algorithms, and expression evaluation.

---

**Note**: This system is designed for educational purposes to demonstrate expression evaluation algorithms and data structure implementation in C++.
