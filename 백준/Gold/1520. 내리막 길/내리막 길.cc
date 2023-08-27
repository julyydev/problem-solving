#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

int M, N;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int dfs(const vector<vector<int>>& heights, vector<vector<int>>& dp,
        Point cur) {
    if (dp[cur.x][cur.y] != -1) return dp[cur.x][cur.y];

    dp[cur.x][cur.y] = 0;
    for (int i = 0; i < 4; i++) {
        Point next(cur.x + dx[i], cur.y + dy[i]);
        if (next.x < 0 || next.x >= M || next.y < 0 || next.y >= N ||
            heights[cur.x][cur.y] >= heights[next.x][next.y])
            continue;

        dp[cur.x][cur.y] += dfs(heights, dp, next);
    }
    return dp[cur.x][cur.y];
}

int main() {
    FASTIO();
    cin >> M >> N;
    vector<vector<int>> heights(M, vector<int>(N));
    vector<vector<int>> dp(M, vector<int>(N, -1));
    dp[0][0] = 1;

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++) cin >> heights[i][j];

    cout << dfs(heights, dp, {M - 1, N - 1}) << "\n";

    return 0;
}