#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int N, M, t, x1, y1, x2, y2;
    cin >> N >> M;
    vector<vector<int>> prefix_sum(N + 1, vector<int>(N + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> t;
            prefix_sum[i][j] = prefix_sum[i - 1][j] + prefix_sum[i][j - 1] -
                               prefix_sum[i - 1][j - 1] + t;
        }
    }

    while (M--) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << prefix_sum[x2][y2] - prefix_sum[x2][y1 - 1] -
                    prefix_sum[x1 - 1][y2] + prefix_sum[x1 - 1][y1 - 1]
             << "\n";
    }

    return 0;
}