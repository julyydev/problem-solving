#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Problem {
    int d, w;
    Problem() {}
    Problem(int d, int w) : d(d), w(w) {}

    bool operator<(const Problem& p) const {
        if (w == p.w) return d < p.d;
        return w < p.w;
    }
};

struct cmp {
    bool operator()(Problem a, Problem b) { return a.d < b.d; }
};

int main() {
    FASTIO();
    int n, d, w, max_day = 0;
    cin >> n;

    priority_queue<Problem, vector<Problem>, cmp> sorted_problems;
    for (int i = 0; i < n; i++) {
        cin >> d >> w;
        sorted_problems.push({d, w});
        max_day = max(max_day, d);
    }

    int sum = 0;
    priority_queue<Problem> pq;
    for (int day = max_day; day >= 1; day--) {
        while (!sorted_problems.empty()) {
            if (sorted_problems.top().d < day) break;

            pq.push(sorted_problems.top());
            sorted_problems.pop();
        }

        if (pq.empty()) continue;
        sum += pq.top().w;
        pq.pop();
    }
    cout << sum << "\n";

    return 0;
}
