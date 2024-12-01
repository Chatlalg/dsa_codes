#include <iostream>
#include <stack>
#include <cmath>  // For pow()
#include <cctype> // For isdigit()

using namespace std;

// Function to evaluate a postfix expression
int evaluatePostfix(string postExp) {
    stack<int> stk;

    // Traverse the expression
    for (char ch : postExp) {
        // If the character is a digit, push it to the stack
        if (isdigit(ch)) {
            stk.push(ch - '0'); // Convert char to int
        }
        // If the character is an operator, pop two elements and apply the operator
        else {
            int val1 = stk.top();
            stk.pop();
            int val2 = stk.top();
            stk.pop();

            switch (ch) {
                case '+':
                    stk.push(val2 + val1);
                    break;
                case '-':
                    stk.push(val2 - val1);
                    break;
                case '*':
                    stk.push(val2 * val1);
                    break;
                case '/':
                    stk.push(val2 / val1);
                    break;
                case '^':
                    stk.push(pow(val2, val1));
                    break;
                default:
                    cout << "Invalid operator: " << ch << endl;
            }
        }
    }

    // The final result will be at the top of the stack
    return stk.top();
}

bool isOperand(char c) {
    // If the character is a digit then it must
    // be an operand
    return isdigit(c);
}

int evaluatePrefix(string exprsn) {
    stack<int> stk;

    for (int j = exprsn.size() - 1; j >= 0; j--) {

        // If the character is a digit, push it to the stack
        if (isOperand(exprsn[j]))
            stk.push(exprsn[j] - '0');  // Convert char to int

        else {
            // Operator encountered
            int o1 = stk.top();
            stk.pop();
            int o2 = stk.top();
            stk.pop();

            // Apply the operator
            switch (exprsn[j]) {
                case '+':
                    stk.push(o1 + o2);
                    break;
                case '-':
                    stk.push(o1 - o2);
                    break;
                case '*':
                    stk.push(o1 * o2);
                    break;
                case '/':
                    stk.push(o1 / o2);
                    break;
                default:
                    cout << "Invalid operator: " << exprsn[j] << endl;
            }
        }
    }

    return stk.top();  // Return the final result
}

int main() {
    // string postExp = "4232++2*8/+";  // Postfix expression
    // string preExp = "+4232/28";  // Prefix expression

    // Evaluate the postfix expression
    cout << "Postfix evaluation: " << evaluatePostfix("243+-") << endl;

    // Evaluate the prefix expression
    cout << "Prefix evaluation: " << evaluatePrefix("-2+43") << endl;

    return 0;
}
