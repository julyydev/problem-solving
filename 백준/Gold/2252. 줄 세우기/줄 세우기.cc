#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Node {
    int in_degree;
    vector<int> outs;
    Node() : in_degree(0) {}
};

bool topology_sort(vector<Node>& graph, vector<int>& result, const int& n) {
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (graph[i].in_degree == 0) q.push(i);

    for (int i = 1; i <= n; i++) {
        if (q.empty()) return false;

        int cur = q.front();
        q.pop();
        result[i] = cur;

        for (const int& out : graph[cur].outs)
            if (--graph[out].in_degree == 0) q.push(out);
    }

    return true;
}

int main() {
    FASTIO();
    int N, M, a, b;
    cin >> N >> M;

    vector<Node> graph(N + 1);
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        graph[b].in_degree++;
        graph[a].outs.push_back(b);
    }

    vector<int> result(N + 1);
    topology_sort(graph, result, N);

    for (int i = 1; i <= N; i++) cout << result[i] << " ";
    cout << "\n";

    return 0;
}