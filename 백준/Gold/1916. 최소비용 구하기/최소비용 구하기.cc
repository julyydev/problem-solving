#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define io() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define INF 100000000
using namespace std;

struct Edge {
    int end, weight;
    Edge(int end, int weight) : end(end), weight(weight){};
};

vector<vector<Edge>> graph;
vector<int> dist;

int dijkstra(int S, int E) {
    priority_queue<pair<int, int>> q;
    q.push(make_pair(0, S));
    dist[S] = 0;

    while (!q.empty()) {
        int cur = q.top().second;
        int cost = -q.top().first;
        q.pop();

        if (cost > dist[cur]) {
            if (cur == E)
                return dist[E];
            else
                continue;
        }

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].end;
            int nextCost = cost + graph[cur][i].weight;
            if (nextCost < dist[next]) {
                dist[next] = nextCost;
                q.push(make_pair(-nextCost, next));
            }
        }
    }

    return dist[E];
}

int main() {
    io();
    int N, M, S, E;
    cin >> N >> M;
    graph.resize(N + 1);
    for (int i = 0; i < M; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        graph[s].push_back(Edge(e, w));
    }
    cin >> S >> E;

    dist.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
    }
    cout << dijkstra(S, E) << "\n";

    return 0;
}