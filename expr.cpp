#include <iostream>
#include <string>
using namespace std;

const int SIZE = 100;
char arr[SIZE];
int top = -1;

// check if stack is full
bool isFull() {
    return top == SIZE - 1;
}

// check if stack is empty
bool isEmpty() {
    return top == -1;
}

// push value
void push(char val) {
    if (isFull()) {
        cout << "Overflow!\n";
    }
    else {
        arr[++top] = val;
    }
}

// pop the top value and return it
char pop() {
    if (isEmpty()) {
        cout << "Underflow!\n";
    }
    else {
        return arr[top--];
    }
}

// return the top value
char peek() {
    if (isEmpty()) {
        cout << "\nStack is empty!";
        return '\0';
    }
    return arr[top];
}

void display() {
    if (isEmpty()) {
        cout << "Stack is empty!\n";
    }
    else {
        cout << "Stack: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
}

// check if the bracket pairs are valid
bool checkPair(char First, char Second) {
    return ((Second == ')' && First == '(') ||
        (Second == '}' && First == '{') ||
        (Second == ']' && First == '['));
}

bool isBalanced(const string& expr) {
    for (char c : expr) {
        if (c == '(' || c == '{' || c == '[') {
            push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (isEmpty()) {
                return false;
            }
            char topChar = peek();
            pop();
            // or, char topChar() = pop();
            if (!checkPair(topChar, c)) {
                return false;
            }
        }
        display();
    }
    return isEmpty();
}

bool isOperand(char c) {
    return isalnum(c);
}

int precendence(char op) {
    switch (op) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

bool isOperator(char c) {
    return c == '+' or c == '-' or c == '*' or c == '/' or c == '^';
}

/*
Scan the infix expression from left to right.
If the scanned character is an operand, put it in the postfix expression.
Otherwise, do the following
If the precedence and associativity of the scanned operator are greater than the precedence and associativity of the operator in the stack [or the stack is empty or the stack contains a ‘(‘ ], then push it in the stack. [‘^‘ operator is right associative and other operators like ‘+‘,’–‘,’*‘ and ‘/‘ are left-associative].
Check especially for a condition when the operator at the top of the stack and the scanned operator both are ‘^‘. In this condition, the precedence of the scanned operator is higher due to its right associativity. So it will be pushed into the operator stack.
In all the other cases when the top of the operator stack is the same as the scanned operator, then pop the operator from the stack because of left associativity due to which the scanned operator has less precedence.
Else, Pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator.
After doing that Push the scanned operator to the stack. (If you encounter parenthesis while popping then stop there and push the scanned operator in the stack.)
If the scanned character is a ‘(‘, push it to the stack.
If the scanned character is a ‘)’, pop the stack and output it until a ‘(‘ is encountered, and discard both the parenthesis.
Repeat steps 2-5 until the infix expression is scanned.
Once the scanning is over, Pop the stack and add the operators in the postfix expression until it is not empty.
Finally, print the postfix expression.
*/

void infixToPostfix(string& expr) {
    int n = expr.length();
    for (int i = 0, j = -1; i < n; i++) {
        if (isOperand(expr[i])) {
            expr[++j] = expr[i];
        }
        else if (expr[i] == '(') {
            push(expr[i]);
        }
        else if (expr[i] == ')') {
            while (!isEmpty() and peek() == '(') {
                expr[++j] = peek();
                pop();
            }
        }
        else if (isOperator(expr[i]) {
            while (!isEmpty() and precendence(peek()) >= precendence(expr[i]) {
                push(expr[i]);
            }
        }

        while (!isEmpty()) {
            if (peek() == '(') {
                cout << "Invalid expression!\n";
                return;
            }
        }
        expr[++j] = peek();
        pop();
        expr[j] = '\0';
    }
}

int main() {
    string s;
    cin >> s;
    /*    if (isBalanced(s)) {
            cout << "Balanced\n";
        }
        else {
            cout << "Not balanced\n";
        } */
    cout << infixToPostfix(s) << endl;
    return 0;
}

