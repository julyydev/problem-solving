#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

enum Cell {
    EMPTY,
    WALL,
    HOLE,
};

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

struct Point {
    int x, y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}

    bool operator==(const Point& p) const { return x == p.x && y == p.y; }
};

struct Data {
    Point red_ball, blue_ball;
    int count;
    Data(Point red_ball, Point blue_ball, int count)
        : red_ball(red_ball), blue_ball(blue_ball), count(count) {}
};

enum Result {
    NONE,
    RED,
    BLUE,
};

class Board {
    int n, m;
    vector<vector<Cell>> map;
    Point red_ball, blue_ball;

   public:
    Board() {}

   private:
    Result tilt(Point& red_ball, Point& blue_ball, int d) {
        int red_dist = 0, blue_dist = 0;

        while (map[red_ball.x + dx[d]][red_ball.y + dy[d]] != Cell::WALL &&
               map[red_ball.x][red_ball.y] != Cell::HOLE) {
            red_ball = {red_ball.x + dx[d], red_ball.y + dy[d]};
            red_dist++;
        }

        while (map[blue_ball.x + dx[d]][blue_ball.y + dy[d]] != Cell::WALL &&
               map[blue_ball.x][blue_ball.y] != Cell::HOLE) {
            blue_ball = {blue_ball.x + dx[d], blue_ball.y + dy[d]};
            blue_dist++;
        }

        if (map[blue_ball.x][blue_ball.y] == Cell::HOLE) return Result::BLUE;
        if (map[red_ball.x][red_ball.y] == Cell::HOLE) return Result::RED;

        if (red_ball == blue_ball) {
            if (red_dist > blue_dist)
                red_ball = {red_ball.x - dx[d], red_ball.y - dy[d]};
            else
                blue_ball = {blue_ball.x - dx[d], blue_ball.y - dy[d]};
        }

        return Result::NONE;
    }

   public:
    void init() {
        cin >> n >> m;
        map.resize(n, vector<Cell>(m));

        char c;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> c;
                switch (c) {
                    case '#':
                        map[i][j] = Cell::WALL;
                        break;
                    case '.':
                        map[i][j] = Cell::EMPTY;
                        break;
                    case 'O':
                        map[i][j] = Cell::HOLE;
                        break;
                    case 'R':
                        red_ball = {i, j};
                        map[i][j] = Cell::EMPTY;
                        break;
                    case 'B':
                        blue_ball = {i, j};
                        map[i][j] = Cell::EMPTY;
                        break;
                }
            }
        }
    }

    int bfs() {
        queue<Data> q;
        q.push({red_ball, blue_ball, 0});

        while (!q.empty()) {
            Data cur = q.front();
            q.pop();

            if (cur.count == 10) break;

            for (int i = 0; i < 4; i++) {
                Point next_red_ball = cur.red_ball,
                      next_blue_ball = cur.blue_ball;

                Result result = tilt(next_red_ball, next_blue_ball, i);
                if (result == Result::BLUE) continue;
                if (result == Result::RED) return cur.count + 1;

                q.push({next_red_ball, next_blue_ball, cur.count + 1});
            }
        }

        return -1;
    }
};

int main() {
    FASTIO();
    Board board;
    board.init();
    cout << board.bfs() << "\n";

    return 0;
}