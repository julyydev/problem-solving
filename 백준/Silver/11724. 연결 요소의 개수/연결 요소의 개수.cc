#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int cc = 0;
bool isVisited[1001];
vector<vector<int>> graph;

void bfs(int n) {
    queue<int> q;
    q.push(n);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            if (!isVisited[graph[cur][i]]) {
                q.push(graph[cur][i]);
                isVisited[graph[cur][i]] = true;
            }
        }
    }
}

int main() {
    int N, M, u, v;
    cin >> N >> M;
    graph.resize(N + 1);

    while (M--) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        if (!isVisited[i]) {
            bfs(i);
            cc++;
        }
    }
    cout << cc << "\n";

    return 0;
}