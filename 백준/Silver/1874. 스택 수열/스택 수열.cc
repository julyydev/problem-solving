// https://www.acmicpc.net/problem/1874
// written by julyy

#include <iostream>
#include <stack>
#include <list>
#include <vector>
using namespace std;

int main() {
    list<int> li;
    stack<int> stk;
    vector<char> answer;
    int n, num;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num;
        li.push_back(num);
    }

    for (int i = 1; i <= n; i++) {
        stk.push(i);
        answer.push_back('+');
        while (stk.top() == li.front()) {
            stk.pop();
            answer.push_back('-');
            li.erase(li.begin());
            if (stk.empty())
                break;
        }
    }
    
    if (stk.empty()) {
        for (int i = 0; i < 2 * n; i++) {
            cout << answer[i] << '\n';
        }
    }
    else
        cout << "NO";
    
    return 0;
}
