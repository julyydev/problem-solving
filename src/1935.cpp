// https://www.acmicpc.net/problem/1935
// written by julyy

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;
    double num, x, y;
    string s;
    cin >> n >> s;

    stack<double> stk;
    vector<double> vec;

    for (int i = 0; i < n; i++) {
        cin >> num;
        vec.push_back(num);
    }

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            y = stk.top();
            stk.pop();
            x = stk.top();
            stk.pop();
            if (s[i] == '+')
                x += y;
            else if (s[i] == '-')
                x -= y;
            else if (s[i] == '*')
                x *= y;
            else if (s[i] == '/')
                x /= y;
            stk.push(x);
        }
        else
            stk.push(vec[s[i] - 'A']);
    }
    cout << fixed;
    cout.precision(2);
    cout << stk.top();
    
    return 0;
}
