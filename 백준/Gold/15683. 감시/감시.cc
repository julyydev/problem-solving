#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

int n, m;

void observe(vector<vector<int>>& map, const Point& point, int direction) {
    const int dx[4] = {0, 1, 0, -1};  // →, ↓, ←, ↑
    const int dy[4] = {1, 0, -1, 0};

    Point cur = point;
    while (1) {
        Point next(cur.x + dx[direction], cur.y + dy[direction]);
        if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= m ||
            map[next.x][next.y] == 6)
            return;

        if (map[next.x][next.y] == 0) map[next.x][next.y] = -1;
        cur = next;
    }
}

const vector<vector<vector<int>>> directions = {
    {{0}, {1}, {2}, {3}},
    {{0, 2}, {1, 3}},
    {{0, 1}, {1, 2}, {2, 3}, {3, 0}},
    {{0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1}},
    {{0, 1, 2, 3}}};

void backtracking(int deps, vector<vector<int>> map, const vector<Point>& cctv,
                  int& min_blind_spot) {
    if (deps == cctv.size()) {
        int blind_spot = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (map[i][j] == 0) blind_spot++;

        min_blind_spot = min(min_blind_spot, blind_spot);
        return;
    }

    for (auto direction : directions[map[cctv[deps].x][cctv[deps].y] - 1]) {
        vector<vector<int>> temp = map;
        for (auto d : direction) observe(temp, cctv[deps], d);
        backtracking(deps + 1, temp, cctv, min_blind_spot);
    }
}

int main() {
    FASTIO();
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m));
    vector<Point> cctv;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] >= 1 && map[i][j] <= 5) cctv.push_back({i, j});
        }
    }

    int min_blind_spot = 100;
    backtracking(0, map, cctv, min_blind_spot);
    cout << min_blind_spot << "\n";

    return 0;
}