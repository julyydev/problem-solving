#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

vector<int> bfs(const int& n, const vector<vector<int>>& graph,
                vector<bool>& isVisited) {
    vector<int> parent(n + 1);
    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int n : graph[cur]) {
            if (!isVisited[n]) {
                parent[n] = cur;
                q.push(n);
                isVisited[n] = true;
            }
        }
    }
    return parent;
}

int main() {
    FASTIO();
    int N, u, v;
    cin >> N;
    vector<vector<int>> graph(N + 1);
    vector<bool> isVisited(N + 1, false);

    for (int i = 0; i < N - 1; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> parent = bfs(N, graph, isVisited);
    for (int i = 2; i < parent.size(); i++) cout << parent[i] << "\n";

    return 0;
}