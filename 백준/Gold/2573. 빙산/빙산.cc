#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

class Iceberg {
    int time = 0, num = 0;
    int n, m;
    vector<vector<int>> map;

   public:
    Iceberg() {}

   private:
    void dfs(Point cur, vector<vector<bool>>& is_visited, int& count) {
        for (int i = 0; i < 4; i++) {
            Point next(cur.x + dx[i], cur.y + dy[i]);
            if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= m ||
                is_visited[next.x][next.y] || map[next.x][next.y] == 0)
                continue;

            is_visited[next.x][next.y] = true;
            dfs(next, is_visited, ++count);
        }
    }

    bool is_separated() {
        int count = 0;
        [&]() {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (map[i][j] == 0) continue;

                    vector<vector<bool>> is_visited(n, vector<bool>(m, 0));
                    is_visited[i][j] = true;
                    count++;
                    dfs({i, j}, is_visited, count);

                    return;
                }
            }
        }();

        if (count != num) return true;

        if (num == 0) {
            time = 0;
            return true;
        }

        return false;
    }

   public:
    void init() {
        cin >> n >> m;
        map.resize(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> map[i][j];
                if (map[i][j] > 0) num++;
            }
        }
    }

    void melt() {
        while (!is_separated()) {
            vector<vector<int>> diff(n, vector<int>(m, 0));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (map[i][j] == 0) continue;

                    int d = 0;
                    for (int k = 0; k < 4; k++) {
                        Point next(i + dx[k], j + dy[k]);
                        if (next.x < 0 || next.x >= n || next.y < 0 ||
                            next.y >= m || map[next.x][next.y] > 0)
                            continue;
                        d++;
                    }

                    diff[i][j] = d;
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (map[i][j] == 0) continue;

                    map[i][j] = max(map[i][j] - diff[i][j], 0);
                    if (map[i][j] == 0) num--;
                }
            }

            time++;
        }
    }

    int get_time() { return time; }
};

int main() {
    FASTIO();
    Iceberg iceberg;
    iceberg.init();
    iceberg.melt();
    cout << iceberg.get_time() << "\n";

    return 0;
}