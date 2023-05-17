#include <iostream>
#include <queue>
#include <vector>
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
    void dijkstra(const int& start, const int& end) {
        vector<int> dist(V + 1, INF);
        vector<int> route(V + 1, INF);
        priority_queue<Edge> pq;
        pq.push({start, 0});
        dist[start] = 0;
        route[start] = 0;

        while (!pq.empty()) {
            Edge cur = pq.top();
            pq.pop();

            if (cur.w > dist[cur.v]) continue;

            for (const Edge& e : graph[cur.v]) {
                Edge next(e.v, cur.w + e.w);

                if (next.w < dist[next.v]) {
                    pq.push(next);
                    dist[next.v] = next.w;
                    route[next.v] = cur.v;
                }
            }
        }

        vector<int> routes;
        int temp = end;
        while (temp) {
            routes.push_back(temp);
            temp = route[temp];
        }

        cout << dist[end] << "\n";
        cout << routes.size() << "\n";
        for (int i = routes.size() - 1; i >= 0; i--) cout << routes[i] << " ";
        cout << "\n";

        return;
    }
};

int main() {
    FASTIO();
    int n, m, s, e, c, start, end;
    cin >> n >> m;

    vector<vector<Edge>> init_graph(n + 1);

    for (int i = 0; i < m; i++) {
        cin >> s >> e >> c;
        init_graph[s].push_back({e, c});
    }
    cin >> start >> end;
    Graph graph(n, m, init_graph);
    graph.dijkstra(start, end);

    return 0;
}