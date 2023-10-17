#include <iostream>
#include <queue>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int n, x;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        cin >> x;
        pq.push(x);
    }

    int sum = 0;
    while (pq.size() > 1) {
        int temp = pq.top();
        pq.pop();
        temp += pq.top();
        pq.pop();
        sum += temp;
        pq.push(temp);
    }
    cout << sum << "\n";

    return 0;
}
