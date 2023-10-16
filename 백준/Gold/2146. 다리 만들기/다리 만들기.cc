#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Point {
    int x, y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
};

struct Data {
    Point point;
    int length;
    Data(Point point, int length) : point(point), length(length) {}
};

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

class Sea {
    int n;
    vector<vector<int>> island;
    int min_bridge = 1000000;

   public:
    Sea() {}

   private:
    void bfs_island(Point start, const vector<vector<int>>& map,
                    vector<vector<bool>>& is_visited, int index) {
        queue<Point> q;
        q.push(start);
        is_visited[start.x][start.y] = true;
        island[start.x][start.y] = index;

        while (!q.empty()) {
            Point cur = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                Point next(cur.x + dx[i], cur.y + dy[i]);
                if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= n ||
                    map[next.x][next.y] == 0 || is_visited[next.x][next.y])
                    continue;

                q.push(next);
                is_visited[next.x][next.y] = true;
                island[next.x][next.y] = index;
            }
        }
    }

    void bfs_bridge(Point start) {
        int start_island = island[start.x][start.y];

        queue<Data> q;
        vector<vector<bool>> is_visited(n, vector<bool>(n, false));
        q.push({start, 0});
        is_visited[start.x][start.y] = true;

        while (!q.empty()) {
            Data cur = q.front();
            q.pop();

            if (island[cur.point.x][cur.point.y] != 0 &&
                island[cur.point.x][cur.point.y] != start_island) {
                min_bridge = min(min_bridge, cur.length - 1);
                break;
            }

            for (int i = 0; i < 4; i++) {
                Point next(cur.point.x + dx[i], cur.point.y + dy[i]);
                if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= n ||
                    is_visited[next.x][next.y] ||
                    island[next.x][next.y] == start_island)
                    continue;

                q.push({next, cur.length + 1});
                is_visited[next.x][next.y] = true;
            }
        }
    }

   public:
    void init() {
        cin >> n;
        vector<vector<int>> map(n, vector<int>(n));
        island.resize(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) cin >> map[i][j];

        int num_island = 0;
        vector<vector<bool>> is_visited(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] == 0 || is_visited[i][j]) continue;
                bfs_island({i, j}, map, is_visited, ++num_island);
            }
        }
    }

    int get_min_bridge() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (island[i][j] == 0) continue;
                bfs_bridge({i, j});
            }
        }

        return min_bridge;
    }
};

int main() {
    FASTIO();
    Sea sea;
    sea.init();
    cout << sea.get_min_bridge() << "\n";

    return 0;
}