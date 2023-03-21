#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> map;
vector<vector<bool>> isVisited;
int N, M;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

struct Point {
    int x, y, count;
    Point(int x, int y, int count) : x(x), y(y), count(count) {}
};

int bfs() {
    queue<Point> q;
    q.push({0, 0, 1});
    isVisited[0][0] = true;

    while (!q.empty()) {
        Point cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            Point next(cur.x + dx[i], cur.y + dy[i], cur.count + 1);
            if (next.x < 0 || next.x >= N || next.y < 0 || next.y >= M)
                continue;
            if (map[next.x][next.y] == 1 && !isVisited[next.x][next.y]) {
                if (next.x == N - 1 && next.y == M - 1) return next.count;
                q.push(next);
                isVisited[next.x][next.y] = true;
            }
        }
    }
}

int main() {
    cin >> N >> M;
    map.resize(N, vector<int>(M));
    isVisited.resize(N, vector<bool>(M, false));

    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < M; j++) map[i][j] = s[j] - '0';
    }

    cout << bfs() << "\n";

    return 0;
}