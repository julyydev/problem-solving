#include <iostream>
using namespace std;

long long dp[101];

int main() {
    int T, N;
    cin >> T;

    for (int i = 1; i <= 3; i++) dp[i] = 1;
    for (int i = 4; i <= 100; i++) dp[i] = dp[i - 2] + dp[i - 3];

    while (T--) {
        cin >> N;
        cout << dp[N] << "\n";
    }

    return 0;
}
