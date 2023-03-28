#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct RGB {
    int r, g, b;
    RGB() {}
    RGB(int r, int g, int b) : r(r), g(g), b(b) {}
};

int main() {
    FASTIO();
    int N, r, g, b, nr, ng, nb;
    cin >> N;
    vector<RGB> dp(N);
    cin >> r >> g >> b;
    dp[0] = RGB(r, g, b);

    for (int i = 1; i < N; i++) {
        cin >> r >> g >> b;
        nr = r + min(dp[i - 1].g, dp[i - 1].b);
        ng = g + min(dp[i - 1].r, dp[i - 1].b);
        nb = b + min(dp[i - 1].r, dp[i - 1].g);
        dp[i] = RGB(nr, ng, nb);
    }
    cout << min(dp[N - 1].r, min(dp[N - 1].g, dp[N - 1].b)) << "\n";

    return 0;
}