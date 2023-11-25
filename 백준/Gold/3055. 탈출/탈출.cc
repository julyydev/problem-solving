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

enum Cell {
    EMPTY,
    WATER,
    ROCK,
    BEAVER,
};

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
const int INF = 100000000;

struct Data {
    Point point;
    int time;
    Data(Point point, int time) : point(point), time(time) {}
};

class Forest {
    int r, c;
    vector<vector<Cell>> map;
    vector<vector<int>> when_water;
    Point hedgehog;

   public:
    Forest() {}

   private:
    void set_when_water() {
        when_water.resize(r, vector<int>(c, INF));
        queue<Data> q;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (map[i][j] != Cell::WATER) continue;

                when_water[i][j] = 0;
                q.push({{i, j}, 0});
            }
        }

        while (!q.empty()) {
            Data cur = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                Point next(cur.point.x + dx[i], cur.point.y + dy[i]);
                if (next.x < 0 || next.x >= r || next.y < 0 || next.y >= c ||
                    when_water[next.x][next.y] != INF ||
                    map[next.x][next.y] == Cell::ROCK ||
                    map[next.x][next.y] == Cell::BEAVER)
                    continue;

                when_water[next.x][next.y] = cur.time + 1;
                q.push({next, cur.time + 1});
            }
        }
    }

    void move_hedgehog(int& time) {
        queue<Data> q;
        vector<vector<bool>> is_visited(r, vector<bool>(c, false));
        q.push({hedgehog, 0});

        while (!q.empty()) {
            Data cur = q.front();
            q.pop();

            if (map[cur.point.x][cur.point.y] == Cell::BEAVER) {
                time = cur.time;
                return;
            }

            for (int i = 0; i < 4; i++) {
                Point next(cur.point.x + dx[i], cur.point.y + dy[i]);
                if (next.x < 0 || next.x >= r || next.y < 0 || next.y >= c ||
                    is_visited[next.x][next.y] ||
                    map[next.x][next.y] == Cell::ROCK ||
                    when_water[next.x][next.y] <= cur.time + 1)
                    continue;

                q.push({next, cur.time + 1});
                is_visited[next.x][next.y] = true;
            }
        }

        time = -1;
        return;
    }

   public:
    void init() {
        cin >> r >> c;
        map.resize(r, vector<Cell>(c));

        char x;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> x;
                switch (x) {
                    case '.':
                        map[i][j] = Cell::EMPTY;
                        break;
                    case '*':
                        map[i][j] = Cell::WATER;
                        break;
                    case 'X':
                        map[i][j] = Cell::ROCK;
                        break;
                    case 'D':
                        map[i][j] = Cell::BEAVER;
                        break;
                    case 'S':
                        map[i][j] = Cell::EMPTY;
                        hedgehog = {i, j};
                        break;
                }
            }
        }
    }

    int get_time() {
        int time = 0;
        set_when_water();
        move_hedgehog(time);

        return time;
    }
};

int main() {
    FASTIO();
    Forest forest;
    forest.init();

    int time = forest.get_time();
    if (time == -1)
        cout << "KAKTUS\n";
    else
        cout << time << "\n";

    return 0;
}