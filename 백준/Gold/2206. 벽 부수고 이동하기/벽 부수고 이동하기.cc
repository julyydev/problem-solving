#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Point {
    int x, y, dist;
    bool canBreak;
    Point(int x, int y, int dist, bool canBreak)
        : x(x), y(y), dist(dist), canBreak(canBreak) {}
};

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int bfs(const int& N, const int& M, const vector<string>& map,
        vector<vector<vector<bool>>> isVisited) {
    queue<Point> q;
    q.push({0, 0, 1, true});
    isVisited[0][0][0] = true;

    while (!q.empty()) {
        Point cur = q.front();
        q.pop();
        if (cur.x == N - 1 && cur.y == M - 1) return cur.dist;

        for (int i = 0; i < 4; i++) {
            Point next(cur.x + dx[i], cur.y + dy[i], cur.dist + 1,
                       cur.canBreak);
            if (next.x < 0 || next.x >= N || next.y < 0 || next.y >= M)
                continue;

            if (isVisited[!next.canBreak][next.x][next.y]) continue;

            if (map[next.x][next.y] == '1') {
                if (!next.canBreak) continue;
                q.push({next.x, next.y, next.dist, false});
                isVisited[1][next.x][next.y] = true;
            } else {
                q.push(next);
                isVisited[!next.canBreak][next.x][next.y] = true;
            }
        }
    }

    return -1;
}

int main() {
    FASTIO();
    int N, M;
    cin >> N >> M;
    vector<string> map(N);
    vector<vector<vector<bool>>> isVisited(
        2, vector<vector<bool>>(N, vector<bool>(M, false)));
    for (int i = 0; i < N; i++) cin >> map[i];

    cout << bfs(N, M, map, isVisited) << "\n";

    return 0;
}