#include <iostream>
#include <queue>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

const int INF = 1e8;

struct Edge {
    int v, w;
    Edge() {}
    Edge(int v, int w) : v(v), w(w) {}
    bool operator<(const Edge& e) const { return w > e.w; }
};

class Graph {
    int V, E;
    vector<vector<Edge>> graph;

   public:
    Graph(int V, int E, const vector<vector<Edge>>& init_graph)
        : V(V), E(E), graph(init_graph) {}
    vector<int> dijkstra(int start) {
        vector<int> dist(V + 1, INF);
        priority_queue<Edge> pq;
        pq.push({start, 0});
        dist[start] = 0;

        while (!pq.empty()) {
            Edge cur = pq.top();
            pq.pop();

            if (cur.w > dist[cur.v]) continue;

            for (const Edge& e : graph[cur.v]) {
                Edge next(e.v, cur.w + e.w);

                if (next.w < dist[next.v]) {
                    pq.push(next);
                    dist[next.v] = next.w;
                }
            }
        }

        return dist;
    }
};

int main() {
    FASTIO();
    int V, E, K, u, v, w;
    cin >> V >> E >> K;
    vector<vector<Edge>> init_graph(V + 1);
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        init_graph[u].push_back({v, w});
    }

    Graph graph(V, E, init_graph);
    vector<int> dist = graph.dijkstra(K);
    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }

    return 0;
}