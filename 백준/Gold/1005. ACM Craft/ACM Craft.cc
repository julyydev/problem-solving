#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Node {
    int in_degree;
    vector<int> ins;
    vector<int> outs;
    Node() : in_degree(0) {}
};

int topology_sort(vector<Node>& graph, const vector<int>& time, const int& n,
                  const int& target) {
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (graph[i].in_degree == 0) q.push(i);

    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (q.empty()) return -1;

        int cur = q.front();
        q.pop();

        int max = 0;
        for (const int& in : graph[cur].ins)
            if (dp[in] > max) max = dp[in];
        dp[cur] = max + time[cur];
        if (cur == target) break;

        for (const int& out : graph[cur].outs)
            if (--graph[out].in_degree == 0) q.push(out);
    }

    return dp[target];
}

int main() {
    FASTIO();
    int T, N, K, X, Y, W;
    cin >> T;

    while (T--) {
        cin >> N >> K;
        vector<int> time(N + 1);
        vector<Node> graph(N + 1);
        for (int i = 1; i <= N; i++) cin >> time[i];
        for (int i = 0; i < K; i++) {
            cin >> X >> Y;
            graph[Y].in_degree++;
            graph[X].outs.push_back(Y);
            graph[Y].ins.push_back(X);
        }
        cin >> W;

        cout << topology_sort(graph, time, N, W) << "\n";
    }

    return 0;
}