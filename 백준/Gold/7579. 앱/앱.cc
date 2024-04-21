#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int n, m;
    cin >> n >> m;

    vector<int> memories(n + 1), costs(n + 1);
    for (int i = 1; i <= n; i++) cin >> memories[i];
    for (int i = 1; i <= n; i++) cin >> costs[i];

    vector<vector<int>> dp(n + 1, vector<int>(10001, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 10000; j++) {
            if (j >= costs[i])
                dp[i][j] =
                    max(dp[i - 1][j], dp[i - 1][j - costs[i]] + memories[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    int min_cost = 100000000;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= 10000; j++)
            if (dp[i][j] >= m) min_cost = min(min_cost, j);

    cout << min_cost << "\n";

    return 0;
}