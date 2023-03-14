#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int, vector<int>, greater<int>> min_heap;
    int N, x;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x;
        if (x == 0) {
            if (min_heap.empty())
                cout << "0\n";
            else {
                cout << min_heap.top() << "\n";
                min_heap.pop();
            }
        } else
            min_heap.push(x);
    }

    return 0;
}