#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> stk;
    
    for (char c : s) {
        if (c == '(') stk.push('(');
        else {
            if (!stk.empty() && stk.top() == '(') stk.pop();
            else return false;
        }
    }

    return stk.empty();
}