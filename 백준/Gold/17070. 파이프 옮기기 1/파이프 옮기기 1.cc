#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Pipe {
    int x, y, d;
    Pipe(int x, int y, int d) : x(x), y(y), d(d) {}
};

void bfs(vector<vector<int>>& dp, const int& N) {
    const int dx[3] = {0, 1, 1};
    const int dy[3] = {1, 0, 1};
    vector<vector<int>> indexs = {{0, 2}, {1, 2}, {0, 1, 2}};

    queue<Pipe> q;
    q.push({0, 1, 0});

    while (!q.empty()) {
        Pipe cur = q.front();
        q.pop();

        for (int i : indexs[cur.d]) {
            Pipe next(cur.x + dx[i], cur.y + dy[i], i);
            if (next.x >= N || next.y >= N || dp[next.x][next.y] == -1)
                continue;
            if (next.d == 2 &&
                (dp[next.x][next.y - 1] == -1 || dp[next.x - 1][next.y] == -1))
                continue;

            q.push(next);
            dp[next.x][next.y]++;
        }
    }

    return;
}

int main() {
    FASTIO();
    int N;
    cin >> N;
    vector<vector<int>> dp(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> dp[i][j];
            if (dp[i][j] == 1) dp[i][j] = -1;
        }
    }

    bfs(dp, N);
    if (dp[N - 1][N - 1] == -1)
        cout << "0\n";
    else
        cout << dp[N - 1][N - 1] << "\n";

    return 0;
}