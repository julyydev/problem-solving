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
    vector<int> dijkstra(const int& start, const vector<int>& targets) {
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

        vector<int> result(targets.size());
        for (int i = 0; i < targets.size(); i++) result[i] = dist[targets[i]];

        return result;
    }
};

int main() {
    FASTIO();
    int V, E, a, b, c, v1, v2;
    cin >> V >> E;
    vector<vector<Edge>> init_graph(V + 1);
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        init_graph[a].push_back({b, c});
        init_graph[b].push_back({a, c});
    }
    cin >> v1 >> v2;

    Graph graph(V, E, init_graph);
    vector<int> start_dist = graph.dijkstra(1, {v1, v2});
    int mid_dist = graph.dijkstra(v1, {v2})[0];
    vector<int> end_dist = graph.dijkstra(V, {v1, v2});

    vector<int> dist(2, 0);
    for (int i = 0; i < 2; i++) {
        if (start_dist[i] == INF)
            dist[i] = INF;
        else
            dist[i] += start_dist[i];
    }
    for (int i = 0; i < 2; i++) {
        if (mid_dist == INF)
            dist[i] = INF;
        else
            dist[i] += mid_dist;
    }
    for (int i = 0; i < 2; i++) {
        if (end_dist[1 - i] == INF)
            dist[i] = INF;
        else
            dist[i] += end_dist[1 - i];
    }

    if (dist[0] == INF && dist[1] == INF)
        cout << "-1\n";
    else
        cout << min(dist[0], dist[1]) << "\n";

    return 0;
}