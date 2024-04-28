#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Assignment {
    int d, w;
    Assignment() {}
    Assignment(int d, int w) : d(d), w(w) {}

    bool operator<(const Assignment& a) const {
        if (w == a.w) return d < a.d;
        return w < a.w;
    }
};

int main() {
    FASTIO();
    int n, d, w, max_day = 0;
    cin >> n;

    vector<Assignment> assignments(n);
    for (int i = 0; i < n; i++) {
        cin >> d >> w;
        assignments[i] = {d, w};
        max_day = max(max_day, d);
    }

    int sum = 0;
    priority_queue<Assignment> pq;
    for (int day = max_day; day >= 1; day--) {
        for (auto a : assignments)
            if (a.d == day) pq.push(a);

        if (pq.empty()) continue;
        sum += pq.top().w;
        pq.pop();
    }
    cout << sum << "\n";

    return 0;
}
