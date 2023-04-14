#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Node {
    int e, w;
    Node(int e, int w) : e(e), w(w) {}
};

void dfs(int cur, int& max_length, int& length, int& max_point,
         const vector<vector<Node>>& graph, vector<bool>& isVisited) {
    isVisited[cur] = true;
    for (int i = 0; i < graph[cur].size(); i++) {
        int next = graph[cur][i].e;
        if (isVisited[next]) continue;

        int temp = length + graph[cur][i].w;
        if (temp > max_length) {
            max_length = temp;
            max_point = next;
        }
        dfs(next, max_length, temp, max_point, graph, isVisited);
    }
    return;
}

int main() {
    FASTIO();
    int n, s, e, w;
    cin >> n;
    vector<vector<Node>> graph(n + 1);
    vector<bool> isVisited(n + 1, false);
    for (int i = 0; i < n - 1; i++) {
        cin >> s >> e >> w;
        graph[s].push_back({e, w});
        graph[e].push_back({s, w});
    }

    int max_length = 0, length = 0, max_point = 0;
    dfs(1, max_length, length, max_point, graph, isVisited);
    isVisited.assign(n + 1, false);
    max_length = 0;
    dfs(max_point, max_length, length, max_point, graph, isVisited);
    cout << max_length << "\n";

    return 0;
}