#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int sum[2][301];

int main() {
    memset(sum, 0, sizeof(sum));

    int n, score;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> score;
        if (i == 1) {
            sum[0][1] = score;
            continue;
        }
        sum[0][i] = max(sum[0][i - 2], sum[1][i - 2]) + score;
        sum[1][i] = sum[0][i - 1] + score;
    }

    cout << max(sum[0][n], sum[1][n]) << '\n';

    return 0;
}