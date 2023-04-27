#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

int evaluate(string expression);
int precedence(char op);
int applyOp(int a, int b, char op);

int main()
{
    string filename;
    cout << "Enter the name of the file: ";
    cin >> filename;

    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cout << "Failed to open file " << filename << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        cout << "Expression: " << line << endl;
        cout << "Result: " << evaluate(line) << endl;
    }

    inputFile.close();
    return 0;
}

int evaluate(string expression)
{
    stack<int> values;
    stack<char> ops;

    for (int i = 0; i < (int)expression.length(); i++)
    {
        if (expression[i] == ' ')
            continue;
        else if (expression[i] == '(')
            ops.push(expression[i]);
        else if (isdigit(expression[i]))
        {
            int val = 0;
            while (i < (int)expression.length() && isdigit(expression[i]))
            {
                val = (val*10) + (expression[i]-'0');
                i++;
            }
            values.push(val);
            i--;
        }
        else if (expression[i] == ')')
        {
            while (!ops.empty() && ops.top() != '(')
            {
                int val2 = values.top();
                values.pop();

                int val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }

            if (!ops.empty())
                ops.pop();
        }
        else
        {
            while (!ops.empty() && precedence(ops.top()) >= precedence(expression[i]))
            {
                int val2 = values.top();
                values.pop();

                int val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }

            ops.push(expression[i]);
        }
    }

    while (!ops.empty())
    {
        int val2 = values.top();
        values.pop();

        int val1 = values.top();
        values.pop();

        char op = ops.top();
        ops.pop();

        values.push(applyOp(val1, val2, op));
    }

    return values.top();
}

int precedence(char op)
{
    return 1;
}

int applyOp(int a, int b, char op)
{
    switch(op)
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b);
    }
    return 0;
}
