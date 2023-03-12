#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

vector<vector<int>> graph(1001);
bool isVisited[1001];

void init() {
    memset(isVisited, false, sizeof(isVisited));
    return;
}

void DFS(int cur) {
    isVisited[cur] = true;
    cout << cur << " ";

    sort(graph[cur].begin(), graph[cur].end());
    for (int i = 0; i < graph[cur].size(); i++) {
        if (!isVisited[graph[cur][i]]) {
            DFS(graph[cur][i]);
        }
    }

    return;
}

void BFS(int V) {
    queue<int> q;
    q.push(V);
    isVisited[V] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << " ";

        sort(graph[cur].begin(), graph[cur].end());
        for (int i = 0; i < graph[cur].size(); i++) {
            if (!isVisited[graph[cur][i]]) {
                q.push(graph[cur][i]);
                isVisited[graph[cur][i]] = true;
            }
        }
    }

    return;
}

int main() {
    int N, M, V;
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }

    init();
    DFS(V);
    cout << "\n";
    init();
    BFS(V);
    cout << "\n";

    return 0;
}