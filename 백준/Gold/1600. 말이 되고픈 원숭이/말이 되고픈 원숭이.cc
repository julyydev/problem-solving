#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

enum Cell {
    EMPTY,
    WALL,
};

struct Point {
    int x, y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
    bool operator==(const Point& p) const { return x == p.x && y == p.y; }
};

struct Data {
    Point point;
    int move, horse;
    Data(Point point, int move, int horse)
        : point(point), move(move), horse(horse) {}
};

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
const int hx[8] = {1, 2, 2, 1, -1, -2, -1, -2};
const int hy[8] = {2, 1, -1, -2, -2, -1, 2, 1};

class Monkey {
    int k, w, h;
    vector<vector<Cell>> map;

   public:
    Monkey() {}

    void init() {
        cin >> k >> w >> h;
        map.resize(h, vector<Cell>(w));
        int x;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> x;
                switch (x) {
                    case 0:
                        map[i][j] = Cell::EMPTY;
                        break;
                    case 1:
                        map[i][j] = Cell::WALL;
                        break;
                }
            }
        }
    }

    int find_min_time() {
        Point target = {h - 1, w - 1};
        queue<Data> q;
        vector<vector<vector<bool>>> is_visited(
            h, vector<vector<bool>>(w, vector<bool>(k + 1, false)));
        q.push({{0, 0}, 0, 0});
        is_visited[0][0][0] = true;

        while (!q.empty()) {
            Data cur = q.front();
            q.pop();

            if (cur.point == target) return cur.move;

            if (cur.horse < k) {
                for (int i = 0; i < 8; i++) {
                    Point next_point(cur.point.x + hx[i], cur.point.y + hy[i]);
                    if (next_point.x < 0 || next_point.x >= h ||
                        next_point.y < 0 || next_point.y >= w ||
                        map[next_point.x][next_point.y] == Cell::WALL ||
                        is_visited[next_point.x][next_point.y][cur.horse + 1])
                        continue;

                    q.push({next_point, cur.move + 1, cur.horse + 1});
                    is_visited[next_point.x][next_point.y][cur.horse + 1] =
                        true;
                }
            }

            for (int i = 0; i < 4; i++) {
                Point next_point(cur.point.x + dx[i], cur.point.y + dy[i]);
                if (next_point.x < 0 || next_point.x >= h || next_point.y < 0 ||
                    next_point.y >= w ||
                    map[next_point.x][next_point.y] == Cell::WALL ||
                    is_visited[next_point.x][next_point.y][cur.horse])
                    continue;

                q.push({next_point, cur.move + 1, cur.horse});
                is_visited[next_point.x][next_point.y][cur.horse] = true;
            }
        }

        return -1;
    }
};

int main() {
    FASTIO();
    Monkey monkey;
    monkey.init();
    cout << monkey.find_min_time() << "\n";

    return 0;
}