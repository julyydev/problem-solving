#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

enum CellType {
    WATER,
    ICE,
};

struct Point {
    int x, y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}

    bool operator<(const Point& p) const {
        if (x == p.x) return y < p.y;
        return x < p.x;
    }
    bool operator==(const Point& p) const { return x == p.x && y == p.y; }
};

struct Data {
    Point point;
    int day;
    Data() {}
    Data(Point point, int day) : point(point), day(day) {}

    bool operator<(const Data& d) const {
        if (day == d.day) return point < d.point;
        return day > d.day;
    }
};

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

class Lake {
    int day;
    int r, c;
    vector<vector<CellType>> map;
    vector<vector<int>> day_map;
    vector<Point> swan_points;

   public:
    Lake(int r, int c, const vector<vector<CellType>>& map,
         const vector<Point>& swan_points)
        : r(r), c(c), day(0), map(map), swan_points(swan_points) {}

   private:
    void ice_bfs() {
        day_map.resize(r, vector<int>(c, -1));
        queue<Point> q;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (map[i][j] == CellType::WATER) {
                    day_map[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            Point cur = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                Point next(cur.x + dx[i], cur.y + dy[i]);
                if (next.x < 0 || next.x >= r || next.x < 0 || next.y >= c ||
                    day_map[next.x][next.y] > -1)
                    continue;

                q.push(next);
                day_map[next.x][next.y] = day_map[cur.x][cur.y] + 1;
            }
        }
    }

    void swan_bfs() {
        Point swan_start = swan_points[0], swan_end = swan_points[1];

        priority_queue<Data> pq;
        vector<vector<bool>> is_visited(r, vector<bool>(c, false));
        pq.push({swan_start, 0});

        while (!pq.empty()) {
            Data cur = pq.top();
            pq.pop();

            if (cur.point == swan_end) return;
            if (cur.day > day) day++;

            for (int i = 0; i < 4; i++) {
                Point next_point(cur.point.x + dx[i], cur.point.y + dy[i]);
                if (next_point.x < 0 || next_point.x >= r || next_point.y < 0 ||
                    next_point.y >= c || is_visited[next_point.x][next_point.y])
                    continue;

                Data next({next_point}, day_map[next_point.x][next_point.y]);
                pq.push(next);
                is_visited[next_point.x][next_point.y] = true;
            }
        }
    }

   public:
    int find_swan_meet_day() {
        ice_bfs();
        swan_bfs();
        return day;
    }
};

int main() {
    FASTIO();
    int R, C;
    char x;
    cin >> R >> C;
    vector<vector<CellType>> map(R, vector<CellType>(C));
    vector<Point> swan_points;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> x;
            switch (x) {
                case '.':
                    map[i][j] = CellType::WATER;
                    break;
                case 'X':
                    map[i][j] = CellType::ICE;
                    break;
                case 'L':
                    swan_points.push_back({i, j});
                    map[i][j] = CellType::WATER;
                    break;
            }
        }
    }

    Lake lake(R, C, map, swan_points);
    cout << lake.find_swan_meet_day() << "\n";

    return 0;
}