#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

const int INF = 1e8;

struct Edge {
    int start, end, cost;
    Edge() {}
    Edge(int start, int end, int cost) : start(start), end(end), cost(cost) {}
};

bool bellman_ford(const int& V, const vector<Edge>& edges, int start) {
    vector<int> dist(V + 1, INF);
    dist[start] = 0;
    for (int i = 0; i < V - 1; i++) {
        for (const Edge& edge : edges) {
            if (dist[edge.start] + edge.cost < dist[edge.end])
                dist[edge.end] = dist[edge.start] + edge.cost;
        }
    }

    for (const Edge& edge : edges)
        if (dist[edge.start] + edge.cost < dist[edge.end]) return false;

    return true;
}

int main() {
    FASTIO();
    int T;
    cin >> T;

    while (T--) {
        int V, E, W, s, e, c;
        cin >> V >> E >> W;
        vector<Edge> edges;

        for (int i = 0; i < E; i++) {
            cin >> s >> e >> c;
            edges.push_back({s, e, c});
            edges.push_back({e, s, c});
        }
        for (int i = 0; i < W; i++) {
            cin >> s >> e >> c;
            edges.push_back({s, e, -c});
        }

        cout << (bellman_ford(V, edges, 1) ? "NO\n" : "YES\n");
    }

    return 0;
}