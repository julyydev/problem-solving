#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int N;
    cin >> N;
    vector<int> arr(N);
    vector<int> dp(N, 1);
    for (int i = 0; i < N; i++) cin >> arr[i];

    int high = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + 1);
        if (dp[i] > high) high = dp[i];
    }
    cout << high << "\n";

    return 0;
}