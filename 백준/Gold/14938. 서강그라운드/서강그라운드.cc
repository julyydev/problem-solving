#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

const int INF = 1000000;

int main() {
    FASTIO();
    int n, m, r, a, b, l;
    cin >> n >> m >> r;
    vector<int> item(n + 1);
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));

    for (int i = 1; i <= n; i++) cin >> item[i];
    for (int i = 1; i <= n; i++) dist[i][i] = 0;
    for (int i = 0; i < r; i++) {
        cin >> a >> b >> l;
        dist[a][b] = dist[b][a] = l;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    int max_sum = 0;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= n; j++)
            if (dist[i][j] <= m) sum += item[j];
        if (sum > max_sum) max_sum = sum;
    }

    cout << max_sum << "\n";

    return 0;
}