#include <bits/stdc++.h>
using namespace std;

// Function to return precedence of operators
int prec(char c) {
    if (c == '^')
        return 3; // Highest precedence
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// The main function to convert infix expression to postfix expression
void infixToPostfix(string s) {
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        // If the scanned character is an operand, add it to the output string
        if (isalnum(c))  // Checks if c is a letter or digit
            result += c;

        // If the scanned character is an ‘(‘, push it to the stack
        else if (c == '(')
            st.push(c);

        // If the scanned character is an ‘)’, pop and add to output until ‘(’ is encountered
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop(); // Remove '(' from the stack
        }

        // If an operator is scanned
        else {
            // Handle precedence and associativity
            while (!st.empty() && 
                   (prec(c) < prec(st.top()) || 
                    (prec(c) == prec(st.top()) && c != '^'))) { // Right-associative check for '^'
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop all the remaining elements from the stack
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    cout << result << endl;
}

int main() {
    string exp = "4+2^3^2*2/8";
    infixToPostfix(exp); // Convert infix to postfix
    return 0;
}
