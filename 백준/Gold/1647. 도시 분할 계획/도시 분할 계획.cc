#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Edge {
    int end;
    int weight;
    Edge() {}
    Edge(int end, int weight) : end(end), weight(weight) {}
    bool operator<(const Edge& e) const { return weight > e.weight; }
};

int prim(int n, const vector<vector<Edge>>& graph) {
    int sum = 0, max_length = 0;
    priority_queue<Edge> pq;
    vector<bool> is_added(n, false);

    is_added[0] = true;
    for (auto e : graph[0]) pq.push(e);

    while (!pq.empty()) {
        Edge cur = pq.top();
        pq.pop();
        if (is_added[cur.end]) continue;

        is_added[cur.end] = true;
        sum += cur.weight;
        max_length = max(max_length, cur.weight);

        for (auto e : graph[cur.end]) pq.push(e);
    }

    return sum - max_length;
}

int main() {
    FASTIO();
    int n, m, a, b, c;
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        graph[a - 1].push_back({b - 1, c});
        graph[b - 1].push_back({a - 1, c});
    }

    cout << prim(n, graph) << "\n";

    return 0;
}