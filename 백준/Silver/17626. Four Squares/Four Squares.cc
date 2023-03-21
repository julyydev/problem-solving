#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;

int main() {
    int n;
    cin >> n;
    dp.resize(n + 1, 0);

    dp[0] = 0;
    for (int i = 1; i * i <= n; i++) dp[i * i] = 1;
    for (int i = 1; i <= n; i++) {
        if (dp[i] == 0) {
            for (int j = 1; j <= i / 2; j++) {
                if (dp[j] == 1 && dp[i - j] == 1) {
                    dp[i] = 2;
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dp[i] == 0) {
            for (int j = 1; j <= i; j++) {
                if (dp[j] == 1 && dp[i - j] == 2) {
                    dp[i] = 3;
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        if (dp[i] == 0) dp[i] = 4;

    cout << dp[n] << "\n";

    return 0;
}