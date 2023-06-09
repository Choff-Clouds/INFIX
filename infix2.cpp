
#include <iostream>
#include <string>
#include <stack>
#include <fstream>
#include <cmath>
using namespace std;

int precedence(char op) {
    return 1;
}

int applyOperation(int a, int b, char op) {
    if (op == '+')
        return a + b;
    if (op == '-')
        return a - b;
    if (op == '*')
        return a * b;
    if (op == '/')
        return a / b;
    if (op == '^') {
       result = pow(a,b);
        return result;
    }
    return 0;
}

int evaluateExpression(const string& expression, int start, int end) {
    stack<char> operators;
    stack<int> operands;

    for (int i = start; i <= end; i++) {
        if (expression[i] == ' ')
            continue;

        if (isdigit(expression[i])) {
            int operand = 0;
            while (i <= end && isdigit(expression[i])) {
                operand = operand * 10 + (expression[i] - '0');
                i++;
            }
            operands.push(operand);
            i--;
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
        int result = evaluateExpression(line, 0, line.length() - 1);
        cout << result << endl;
    }
    //file.close();

    return 0;
}
