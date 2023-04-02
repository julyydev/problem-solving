#include <iostream>
#include <vector>
using namespace std;

string sum(string a, string b) {
    string s = "";
    int i = a.length() - 1, j = b.length() - 1, add = 0, temp;
    while (i >= 0 || j >= 0) {
        temp = (i < 0 ? 0 : a[i] - '0') + (j < 0 ? 0 : b[j] - '0') + add;
        s = to_string(temp % 10) + s;
        add = (temp >= 10 ? 1 : 0);
        i--, j--;
    }
    return add ? "1" + s : s;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<string>> dp(n + 1);

    for (int i = 0; i <= n; i++) {
        dp[i].resize(i + 1);
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                dp[i][j] = "1";
            else
                dp[i][j] = sum(dp[i - 1][j - 1], dp[i - 1][j]);
        }
    }

    cout << dp[n][m] << "\n";

    return 0;
}