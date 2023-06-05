#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Edge {
    int end, weight;
    Edge() {}
    Edge(int end, int weight) : end(end), weight(weight) {}
    bool operator<(const Edge& e) const { return weight > e.weight; }
};

int prim(const vector<vector<Edge>>& graph) {
    int sum = 0;
    priority_queue<Edge> pq;
    vector<bool> is_added(graph.size(), false);

    is_added[1] = true;
    for (const Edge& edge : graph[1]) pq.push(edge);

    while (!pq.empty()) {
        Edge cur = pq.top();
        pq.pop();
        if (is_added[cur.end]) continue;

        is_added[cur.end] = true;
        sum += cur.weight;

        for (const Edge& edge : graph[cur.end]) pq.push(edge);
    }

    return sum;
}

int main() {
    FASTIO();
    int V, E, s, e, w;
    cin >> V >> E;
    vector<vector<Edge>> graph(V + 1);

    for (int i = 0; i < E; i++) {
        cin >> s >> e >> w;
        graph[s].push_back({e, w});
        graph[e].push_back({s, w});
    }

    cout << prim(graph) << "\n";

    return 0;
}