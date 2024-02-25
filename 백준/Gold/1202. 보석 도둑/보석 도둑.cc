#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Jewelry {
    int m, v;
    Jewelry(int m, int v) : m(m), v(v) {}

    bool operator<(const Jewelry& j) const {
        if (v == j.v) return m > j.m;
        return v < j.v;
    }
};

int main() {
    FASTIO();
    int n, k, m, v, c;
    cin >> n >> k;

    priority_queue<Jewelry> jewels;
    for (int i = 0; i < n; i++) {
        cin >> m >> v;
        jewels.push({m, v});
    }

    multiset<int> backpacks;
    for (int i = 0; i < k; i++) {
        cin >> c;
        backpacks.insert(c);
    }

    long long sum = 0;
    while (!jewels.empty() && !backpacks.empty()) {
        Jewelry j = jewels.top();
        jewels.pop();

        auto it = backpacks.lower_bound(j.m);
        if (it == backpacks.end()) continue;

        sum += j.v;
        backpacks.erase(it);
    }
    cout << sum << "\n";

    return 0;
}