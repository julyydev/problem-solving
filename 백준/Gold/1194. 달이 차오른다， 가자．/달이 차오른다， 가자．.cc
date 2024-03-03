#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

struct Point {
    int x, y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}

    bool operator==(const Point& p) const { return x == p.x && y == p.y; }
};

struct Status {
    Point point;
    int keys;
    int count;
    Status() {}
    Status(Point point, int keys, int count)
        : point(point), keys(keys), count(count) {}
};

class Maze {
    int n, m;
    vector<vector<char>> map;
    Point start;

   public:
    Maze() {}

    void init() {
        FASTIO();
        cin >> n >> m;

        map.resize(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> map[i][j];
                if (map[i][j] == '0') start = {i, j};
            }
        }
    }

    int exit() {
        queue<Status> q;
        vector<vector<vector<bool>>> is_visited(
            n, vector<vector<bool>>(m, vector<bool>(1 << 6, false)));
        q.push({start, 0, 0});
        is_visited[start.x][start.y][0] = true;

        while (!q.empty()) {
            auto [cur, keys, count] = q.front();
            q.pop();
            if (is_exit(cur)) return count;

            for (int i = 0; i < 4; i++) {
                Point next(cur.x + dx[i], cur.y + dy[i]);
                if (is_out_range(next) || is_visited[next.x][next.y][keys] ||
                    is_wall(next))
                    continue;

                if (is_door(next) && !can_open_door(next, keys)) continue;

                int next_keys = keys;
                if (is_key(next)) next_keys = add_key(next, keys);

                q.push({next, next_keys, count + 1});
                is_visited[next.x][next.y][next_keys] = true;
            }
        }

        return -1;
    }

   private:
    bool is_out_range(const Point& p) {
        return p.x < 0 || p.x >= n || p.y < 0 || p.y >= m;
    }

    bool is_wall(const Point& p) { return map[p.x][p.y] == '#'; }

    bool is_key(const Point& p) {
        return map[p.x][p.y] >= 'a' && map[p.x][p.y] <= 'f';
    }

    bool is_door(const Point& p) {
        return map[p.x][p.y] >= 'A' && map[p.x][p.y] <= 'F';
    }

    bool is_exit(const Point& p) { return map[p.x][p.y] == '1'; }

    int add_key(const Point& p, const int& keys) {
        return keys | (1 << (map[p.x][p.y] - 'a'));
    }

    bool can_open_door(const Point& p, int keys) {
        return keys & (1 << (map[p.x][p.y] - 'A'));
    }
};

int main() {
    Maze maze;
    maze.init();
    cout << maze.exit() << "\n";

    return 0;
}