#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<vector<int>> stickers(2, vector<int>(n + 1));
        vector<vector<int>> dp(2, vector<int>(2));
        stickers[0][0] = stickers[1][0] = dp[0][0] = dp[1][0] = 0;
        for (int i = 0; i < 2; i++)
            for (int j = 1; j <= n; j++) cin >> stickers[i][j];

        dp[0][1] = stickers[0][1], dp[1][1] = stickers[1][1];
        for (int i = 2; i <= n; i++) {
            stickers[0][i] += max(dp[1][1], max(dp[0][0], dp[1][0]));
            stickers[1][i] += max(dp[0][1], max(dp[0][0], dp[1][0]));
            dp[0][0] = dp[0][1], dp[1][0] = dp[1][1], dp[0][1] = stickers[0][i],
            dp[1][1] = stickers[1][i];
        }
        cout << max(stickers[0][n], stickers[1][n]) << "\n";
    }

    return 0;
}