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
    int N, M, S;
    cin >> N >> M;

    vector<Node> graph(N + 1);
    for (int i = 0; i < M; i++) {
        int first, second;
        cin >> S;
        cin >> first;
        for (int j = 0; j < S - 1; j++) {
            cin >> second;
            graph[second].in_degree++;
            graph[first].outs.push_back(second);
            first = second;
        }
    }

    vector<int> result(N + 1);
    if (!topology_sort(graph, result, N)) cout << "0\n";
    for (int i = 1; i <= N; i++) cout << result[i] << "\n";

    return 0;
}