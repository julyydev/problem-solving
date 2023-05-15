#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

const int INF = 1e8;

struct Edge {
    int e, t;
    Edge() {}
    Edge(int e, int t) : e(e), t(t) {}
};

bool bellman_ford(const int& V, const int& E, const vector<vector<Edge>>& graph,
                  int start) {
    vector<int> dist(V + 1, INF);
    dist[start] = 0;
    for (int i = 0; i < V; i++) {
        for (int j = 1; j <= V; j++) {
            for (Edge cur : graph[j]) {
                if (cur.t + dist[j] < dist[cur.e])
                    dist[cur.e] = cur.t + dist[j];
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        for (Edge cur : graph[i])
            if (cur.t + dist[i] < dist[cur.e]) return false;
    }
    return true;
}

int main() {
    FASTIO();
    int T;
    cin >> T;

    while (T--) {
        int N, M, W, s, e, t;
        cin >> N >> M >> W;
        vector<vector<Edge>> graph(N + 1);

        for (int i = 0; i < M; i++) {
            cin >> s >> e >> t;
            graph[s].push_back({e, t});
            graph[e].push_back({s, t});
        }
        for (int i = 0; i < W; i++) {
            cin >> s >> e >> t;
            graph[s].push_back({e, -t});
        }

        cout << (bellman_ford(N, M, graph, 1) ? "NO\n" : "YES\n");
    }

    return 0;
}