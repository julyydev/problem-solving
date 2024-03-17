#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

struct Point {
    int x, y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
};

struct Data {
    Point point;
    int destroy;
    Data(Point point, int destroy) : point(point), destroy(destroy) {}
};

int main() {
    FASTIO();
    int n, m;
    cin >> n >> m;

    string s;
    vector<vector<int>> map(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            map[i][j] = s[j] - '0';
        }
    }

    deque<Data> dq;
    vector<vector<bool>> is_visited(m, vector<bool>(n, false));
    dq.push_front({{0, 0}, 0});
    is_visited[0][0] = true;
    while (!dq.empty()) {
        auto [cur, destroy] = dq.front();
        dq.pop_front();

        if (cur.x == m - 1 && cur.y == n - 1) {
            cout << destroy << "\n";
            break;
        }

        for (int i = 0; i < 4; i++) {
            Point next(cur.x + dx[i], cur.y + dy[i]);
            if (next.x < 0 || next.x >= m || next.y < 0 || next.y >= n ||
                is_visited[next.x][next.y])
                continue;

            if (map[next.x][next.y] == 0) {
                dq.push_front({next, destroy});
            } else {
                dq.push_back({next, destroy + 1});
            }
            is_visited[next.x][next.y] = true;
        }
    }

    return 0;
}