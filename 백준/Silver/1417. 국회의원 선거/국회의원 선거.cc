#include <iostream>
#include <queue>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int n, x, target, count = 0;
    cin >> n >> target;

    priority_queue<int> q;
    for (int i = 0; i < n - 1; i++) {
        cin >> x;
        q.push(x);
    }

    while (!q.empty() && target <= q.top()) {
        int temp = q.top();
        q.pop();
        q.push(temp - 1);
        target++;
        count++;
    }
    cout << count << "\n";

    return 0;
}