#include <iostream>
#include <stack>
using namespace std;

int main() {
    string s;
    cin >> s;
    stack<char> stack;

    for (char c : s) {
        if (c >= 'A' && c <= 'Z') {
            cout << c;
            continue;
        }

        if (c == '+' || c == '-') {
            while (!stack.empty() && stack.top() != '(') {
                cout << stack.top();
                stack.pop();
            }
            stack.push(c);
        } else if (c == '*' || c == '/') {
            while (!stack.empty() && stack.top() != '(' &&
                   (stack.top() == '*' || stack.top() == '/')) {
                cout << stack.top();
                stack.pop();
            }
            stack.push(c);
        } else if (c == '(')
            stack.push(c);
        else if (c == ')') {
            while (stack.top() != '(') {
                cout << stack.top();
                stack.pop();
            }
            stack.pop();
        }
    }
    while (!stack.empty()) {
        cout << stack.top();
        stack.pop();
    }
    cout << "\n";

    return 0;
}