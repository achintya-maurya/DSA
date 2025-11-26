#include <iostream>
#include <stack>
#include <string>
using namespace std;

/* ============================================================
   3) Program to check if an expression has balanced parentheses
   ============================================================ */

bool isBalanced(string exp) {
    stack<char> st;

    for (char c : exp) {
        if (c == '(' || c == '{' || c == '[')
            st.push(c);

        else if (c == ')' || c == '}' || c == ']') {
            if (st.empty())
                return false;

            char top = st.top();
            st.pop();

            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '['))
                return false;
        }
    }
    return st.empty();
}

/* ============================================================
   4) Convert Infix to Postfix Expression
   ============================================================ */

// precedence
int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

string infixToPostfix(string exp) {
    stack<char> st;
    string result = "";

    for (char c : exp) {

        // operand
        if (isalnum(c))
            result += c;

        // opening bracket
        else if (c == '(')
            st.push(c);

        // closing bracket
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop(); // remove '('
        }

        // operator
        else {
            while (!st.empty() && prec(st.top()) >= prec(c)) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // remaining
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

/* ============================================================
   5) Evaluate Postfix Expression
   ============================================================ */

int evaluatePostfix(string exp) {
    stack<int> st;

    for (char c : exp) {

        if (isdigit(c)) {
            st.push(c - '0'); // convert char → int
        }
        else {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();

            switch (c) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
            }
        }
    }
    return st.top();
}

/* ============================================================
                      MAIN FUNCTION
   ============================================================ */

int main() {

    // Balanced Parentheses Example
    string exp1 = "{[()]}";
    cout << "Is balanced: " << (isBalanced(exp1) ? "Yes" : "No") << endl;

    // Infix → Postfix Example
    string infix = "A+B*(C-D)";
    cout << "Postfix: " << infixToPostfix(infix) << endl;

    // Postfix Evaluation Example
    string postfix = "23*54*+";
    cout << "Postfix Evaluation: " << evaluatePostfix(postfix) << endl;

    return 0;
}
