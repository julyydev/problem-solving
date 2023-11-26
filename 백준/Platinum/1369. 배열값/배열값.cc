#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

const int INF = 100000000;

void set_dp(int n, vector<vector<int>>& dp) {
    for (int i = 1; i < n; i++) {
        if (dp[0][i] == INF) {
            continue;
        }

        if (dp[0][i - 1] == INF) {
            dp[0][i] = INF;
            continue;
        }

        dp[0][i] = dp[0][i] + dp[0][i - 1];
    }

    for (int i = 1; i < n; i++) {
        if (dp[i][0] == INF) {
            continue;
        }

        if (dp[i - 1][0] == INF) {
            dp[i][0] = INF;
            continue;
        }

        dp[i][0] = dp[i][0] + dp[i - 1][0];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (dp[i][j] == INF) {
                continue;
            }

            if (dp[i][j - 1] == INF && dp[i - 1][j] == INF) {
                dp[i][j] = INF;
                continue;
            }

            dp[i][j] += min(dp[i][j - 1], dp[i - 1][j]);
        }
    }
}

int main() {
    FASTIO();
    int n, x;
    cin >> n;

    vector<vector<int>> dp2(n, vector<int>(n));
    vector<vector<int>> dp5(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int two = 0, five = 0;
            cin >> x;

            if (x == 0) {
                dp2[i][j] = dp5[i][j] = INF;
                continue;
            }

            while (x % 2 == 0) {
                two++;
                x /= 2;
            }
            dp2[i][j] = two;

            while (x % 5 == 0) {
                five++;
                x /= 5;
            }
            dp5[i][j] = five;
        }
    }

    set_dp(n, dp2);
    set_dp(n, dp5);

    cout << min(dp2[n - 1][n - 1], dp5[n - 1][n - 1]) << "\n";

    return 0;
}