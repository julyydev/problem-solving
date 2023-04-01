#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    const int INF = 1e9;
    int n, m, s, e, c;
    cin >> n >> m;
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    while (m--) {
        cin >> s >> e >> c;
        dist[s][e] = min(dist[s][e], c);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << (dist[i][j] == INF ? 0 : dist[i][j]) << " ";
        cout << "\n";
    }

    return 0;
}