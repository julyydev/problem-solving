#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int> max_heap;
    int N, x;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x;
        if (x == 0) {
            if (max_heap.empty())
                cout << "0\n";
            else {
                cout << max_heap.top() << "\n";
                max_heap.pop();
            }
        } else
            max_heap.push(x);
    }

    return 0;
}