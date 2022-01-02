// https://www.acmicpc.net/problem/4949
// written by julyy

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    bool check;

    while (1) {
        getline(cin, s);
        if (s == ".")
            break;

        stack<char> stk;
        check = true;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[')
                stk.push(s[i]);   
            else if (s[i] == ')') {
                if (!stk.empty() && stk.top() == '(')
                    stk.pop();
                else {
                    check = false;
                    break;
                }
            }
            else if (s[i] == ']') {
                if (!stk.empty() && stk.top() == '[')
                    stk.pop();
                else {
                    check = false;
                    break;
                }
            }
        }
        if (!stk.empty())
            check = false;
        
        check ? cout << "yes\n" : cout << "no\n";
    }

    return 0;
}
