#include <algorithm>
#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int n, x, temp = 0, prev = 0;
    cin >> n;
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> x;
            if (i == 1) {
                dp[j] = x;
                continue;
            }

            temp = dp[j];
            dp[j] = max(prev, dp[j]) + x;
            prev = temp;
        }
    }

    sort(dp.begin(), dp.end());
    cout << dp.back() << "\n";

    return 0;
}