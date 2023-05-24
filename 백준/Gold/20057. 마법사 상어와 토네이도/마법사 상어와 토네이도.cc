#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

const int dx[4] = {0, 1, 0, -1};  // 좌 하 우 상
const int dy[4] = {-1, 0, 1, 0};

struct Tuple {
    int v, u, p;
    Tuple(int v, int u, int p) : v(v), u(u), p(p) {}
};

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

class Wizzard {
    vector<vector<int>> sand;
    int went_outed_sand;
    int n;

   public:
    Wizzard(vector<vector<int>> init_sand, int N)
        : sand(init_sand), went_outed_sand(0), n(N) {}

   private:
    void _tornado(Point target, int d) {
        Point v = {dx[d], dy[d]};
        Point u = {dx[(d + 1) % 4], dy[(d + 1) % 4]};

        vector<Tuple> datas = {{2, 0, 5},  {1, 1, 10}, {1, -1, 10},
                               {0, 2, 2},  {0, -2, 2}, {0, 1, 7},
                               {0, -1, 7}, {-1, 1, 1}, {-1, -1, 1}};

        int sum = 0;
        for (Tuple t : datas) {
            Point next(target.x + t.v * v.x + t.u * u.x,
                       target.y + t.v * v.y + t.u * u.y);
            int amount = sand[target.x][target.y] * t.p / 100;
            sum += amount;

            if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= n) {
                went_outed_sand += amount;
                continue;
            }

            sand[next.x][next.y] += amount;
        }

        Point rest(target.x + v.x, target.y + v.y);
        if (rest.x < 0 || rest.x >= n || rest.y < 0 || rest.y >= n)
            went_outed_sand += sand[target.x][target.y] - sum;
        else
            sand[rest.x][rest.y] += sand[target.x][target.y] - sum;
        sand[target.x][target.y] = 0;
    }

   public:
    void tornado() {
        Point cur((n - 1) / 2, (n - 1) / 2);

        int m = 1, d = 0;
        while (1) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < m; j++) {
                    if (cur.x == 0 && cur.y == 0) return;
                    Point target(cur.x + dx[d], cur.y + dy[d]);
                    _tornado(target, d);
                    cur = target;
                }
                d = (d + 1) % 4;
            }
            m++;
        }
    }
    int getWentOutedSand() { return went_outed_sand; }
};

int main() {
    FASTIO();
    int N;
    cin >> N;
    vector<vector<int>> init_sand(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> init_sand[i][j];
        }
    }
    Wizzard wizzard(init_sand, N);
    wizzard.tornado();
    cout << wizzard.getWentOutedSand() << "\n";

    return 0;
}