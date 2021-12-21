// https://www.acmicpc.net/problem/9012
// written by julyy

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stack<char> stk;
    string str;
    bool is_vps;
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> str;
        is_vps = true;
        for (int j = 0; j < str.length(); j++) {
            if (str[j] == '(')
                stk.push('(');
            else if (str[j] == ')' && stk.empty())
                is_vps = false;
            else if (str[j] == ')' && !stk.empty())
                stk.pop();
        }
        if (is_vps && stk.empty())
            cout << "YES\n";
        else
            cout << "NO\n";

        while (!stk.empty())
            stk.pop();
    }
    
    return 0;
}
