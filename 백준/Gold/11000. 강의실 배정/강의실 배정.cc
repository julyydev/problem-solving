#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Data {
    int start, end;
    Data() {}
    Data(int start, int end) : start(start), end(end) {}

    bool operator<(const Data& d) const {
        if (start == d.start) return end < d.end;
        return start < d.start;
    }
};

int main() {
    FASTIO();
    int n, s, t;
    cin >> n;

    vector<Data> times(n);
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) {
        cin >> s >> t;
        times[i] = {s, t};
    }
    sort(times.begin(), times.end());
    pq.push(times[0].end);

    for (int i = 1; i < n; i++) {
        if (times[i].start >= pq.top()) pq.pop();
        pq.push(times[i].end);
    }

    cout << pq.size() << "\n";

    return 0;
}