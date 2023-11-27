#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int applyOperator(int operand1, int operand2, char op) {
    switch (op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 != 0) {
                return operand1 / operand2;
            } else {
                cerr << "Error: Division by zero!" << endl;
                exit(1);
            }
        default:
            cerr << "Error: Invalid operator!" << endl;
            exit(1);
    }
}

int evaluatePrefix(const string& expression) {
    stack<int> operands;

    for (int i = expression.size() - 1; i >= 0; --i) {
        char c = expression[i];

        if (isdigit(c)) {
            operands.push(c - '0'); // Convert character to integer
        } else if (isOperator(c)) {
            // Pop the top two operands, apply the operator, and push the result back onto the stack
            int operand1 = operands.top();
            operands.pop();
            int operand2 = operands.top();
            operands.pop();

            int result = applyOperator(operand1, operand2, c);
            operands.push(result);
        }
    }

    // The final result should be on the top of the stack
    return operands.top();
}

int evaluatePostfix(const string& expression) {
    stack<int> operands;

    for (char c : expression) {
        if (isdigit(c)) {
            operands.push(c - '0'); // Convert character to integer
        } else if (isOperator(c)) {
            // Pop the top two operands, apply the operator, and push the result back onto the stack
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();

            int result = applyOperator(operand1, operand2, c);
            operands.push(result);
        }
    }

    // The final result should be on the top of the stack
    return operands.top();
}

int main() {
    string postfixExpression = "23*5+";
    int result = evaluatePostfix(postfixExpression);

    cout << "Result of the postfix expression " << postfixExpression << " is: " << result << endl;
    
    string prefixExp = "+*235";
    cout << "Result of the prefix expression " << prefixExp << " is: " << evaluatePrefix(prefixExp) << endl;

    return 0;
}
