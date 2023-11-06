#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int bfs(int start, int n, const vector<vector<int>>& graph) {
    queue<int> q;
    vector<bool> is_visited(n + 1, false);
    q.push(start);
    is_visited[start] = true;

    int count = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i : graph[cur]) {
            if (is_visited[i]) continue;
            q.push(i);
            is_visited[i] = true;
            count++;
        }
    }

    return count;
}

int main() {
    FASTIO();
    int n, m, a, b;
    cin >> n >> m;

    vector<vector<int>> high_graph(n + 1), low_graph(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        high_graph[a].push_back(b);
        low_graph[b].push_back(a);
    }

    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (bfs(i, n, high_graph) + bfs(i, n, low_graph) == n - 1) count++;
    }

    cout << count << "\n";

    return 0;
}