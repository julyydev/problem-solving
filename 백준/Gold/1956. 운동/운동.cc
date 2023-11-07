#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int v, e, a, b, c;
    cin >> v >> e;

    const int INF = 1000000000;
    vector<vector<int>> dist(v + 1, vector<int>(v + 1, INF));
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        dist[a][b] = c;
    }

    for (int k = 1; k <= v; k++) {
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int min_cycle = INF;
    for (int i = 1; i <= v; i++) min_cycle = min(min_cycle, dist[i][i]);
    cout << (min_cycle == INF ? -1 : min_cycle) << "\n";

    return 0;
}