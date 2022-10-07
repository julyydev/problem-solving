// https://www.acmicpc.net/problem/10773
// written by julyy

#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int> stk;
    int k, n, sum = 0;
    cin >> k;

    for (int i = 0; i < k; i++) {
        cin >> n;
        if (n == 0)
            stk.pop();
        else
            stk.push(n);
    }

    while (!stk.empty()) {
        sum += stk.top();
        stk.pop();
    }
    cout << sum;
    
    return 0;
}
