#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

int N;
vector<vector<int>> map;
vector<vector<bool>> isVisited;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int bfs(int x, int y) {
    queue<Point> q;
    q.push({x, y});
    isVisited[x][y] = true;

    int count = 0;
    while (!q.empty()) {
        Point cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            Point next(cur.x + dx[i], cur.y + dy[i]);

            if (next.x < 0 || next.x >= N || next.y < 0 || next.y >= N)
                continue;
            if (map[next.x][next.y] == 1 && !isVisited[next.x][next.y]) {
                q.push(next);
                isVisited[next.x][next.y] = true;
            }
        }
        count++;
    }

    return count;
}

int main() {
    cin >> N;
    map.resize(N, vector<int>(N));
    isVisited.resize(N, vector<bool>(N, false));

    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < N; j++) map[i][j] = s[j] - '0';
    }

    vector<int> complex;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1 && !isVisited[i][j]) {
                complex.push_back(bfs(i, j));
            }
        }
    }

    sort(complex.begin(), complex.end());
    cout << complex.size() << "\n";
    for (int c : complex) cout << c << "\n";

    return 0;
}