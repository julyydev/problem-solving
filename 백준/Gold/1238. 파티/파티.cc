#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

const int INF = 1e8;

int main() {
    FASTIO();
    int N, M, X, u, v, w;
    cin >> N >> M >> X;
    vector<vector<int>> dist(N + 1, vector<int>(N + 1, INF));
    for (int i = 1; i <= N; i++) dist[i][i] = 0;
    while (M--) {
        cin >> u >> v >> w;
        dist[u][v] = w;
    }

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    int max_dist = 0;
    for (int i = 1; i <= N; i++)
        max_dist = max(max_dist, dist[i][X] + dist[X][i]);

    cout << max_dist << "\n";

    return 0;
}