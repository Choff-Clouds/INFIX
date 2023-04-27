#include <iostream>
#include <string>
#include <stack>
#include <fstream>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int applyOperation(int a, int b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
    }
    return 0;
}

int evaluateExpression(string expression) {
    stack<char> operators;
    stack<int> operands;

    for (int i = start; i <= end; i++) {
        if (expression[i] == ' ')
            continue;

        if (isdigit(expression[i])) {
            int operand = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                operand = operand * 10 + (expression[i] - '0');
                i++;
            }
            i--;
            operands.push(operand);
           
        } else if (expression[i] == '(') {
            operators.push('(');
        } else if (expression[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                int b = operands.top();
                operands.pop();
                int a = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                operands.push(applyOperation(a, b, op));
            }
            operators.pop();
        } else {
            while (!operators.empty() && precedence(operators.top()) >= precedence(expression[i])) {
                int b = operands.top();
                operands.pop();
                int a = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                operands.push(applyOperation(a, b, op));
            }
            operators.push(expression[i]);
        }
    }

    while (!operators.empty()) {
        int b = operands.top();
        operands.pop();
        int a = operands.top();
        operands.pop();
        char op = operators.top();
        operators.pop();
        operands.push(applyOperation(a, b, op));
    }

    return operands.top();
}

int main(int argc, char *argv[]) {
    // Read equations from a file
   //ifstream file(argv[1]);
    string line;
    while (getline(cin, line)) {
        int result = evaluateExpression(line);
        cout << result << endl;
    }
    //file.close();

    return 0;
}
