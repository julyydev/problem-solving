// https://www.acmicpc.net/problem/17298
// written by julyy

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

typedef struct {
    int index;
    int value;
} element;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a;
    cin >> n;

    stack<element> stk;
    vector<int> vec(n, -1);
    element e;

    for (int i = 0; i < n; i++) {
        cin >> a;
        e.index = i;
        e.value = a;

        if (stk.empty())
            stk.push(e);
        else {
            while (stk.top().value < a) {
                vec[stk.top().index] = a;
                stk.pop();
                if (stk.empty())
                    break;
            }
            stk.push(e);
        }
    }
    
    for (int i = 0; i < n; i++)
        cout << vec[i] << ' ';

    return 0;
}
