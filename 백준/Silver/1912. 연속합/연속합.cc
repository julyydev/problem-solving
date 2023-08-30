#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int n, x, ans = INT32_MIN;
    cin >> n;
    vector<int> dp(n);

    for (int i = 0; i < n; i++) {
        cin >> x;
        if (i == 0) {
            dp[i] = x;
            continue;
        }

        if (dp[i - 1] + x > x)
            dp[i] = dp[i - 1] + x;
        else
            dp[i] = x;
    }

    for (int i = 0; i < n; i++) ans = max(ans, dp[i]);
    cout << ans << "\n";

    return 0;
}