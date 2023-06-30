#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int N, M, s, e;
    cin >> N;

    vector<int> arr(N);
    vector<vector<int>> dp(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) cin >> arr[i];

    for (int i = 0; i < N; i++) dp[i][i] = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j + i < N; j++) {
            if (arr[j] != arr[j + i]) continue;
            if (i == 1 || dp[j + 1][j + i - 1] == 1) dp[j][j + i] = 1;
        }
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> s >> e;
        cout << dp[s - 1][e - 1] << "\n";
    }

    return 0;
}