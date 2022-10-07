// https://www.acmicpc.net/problem/9093
// written by julyy

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stack<char> stk;
    string str;
    int t;
    cin >> t;

    cin.ignore();
    for (int i = 0; i < t; i++) {
        getline(cin, str, '\n');
        for (int j = 0; j < str.length(); j++) {
            if (str[j] == ' ') {
                while (!stk.empty()) {
                    cout << stk.top();
                    stk.pop();
                }
                cout << ' ';
            }
            else {
                stk.push(str[j]);
            }
        }
        while (!stk.empty()) {
            cout << stk.top();
            stk.pop();
        }
        cout << '\n';
    }
    
    return 0;
}
