#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

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
    int direction;
    Point point;
    Data(int direction, Point point) : direction(direction), point(point) {}
    bool operator<(const Data& d) const {
        if (direction == d.direction) return d.point < point;
        return direction > d.direction;
    }
};

class Taxi {
    int n, m;
    int fuel;
    Point point;
    vector<vector<int>> map;
    vector<vector<Point>> desinations;

   public:
    Taxi(int n, int m, int fuel, Point point, const vector<vector<int>>& map,
         const vector<vector<Point>>& desinations)
        : n(n),
          m(m),
          fuel(fuel),
          point(point),
          map(map),
          desinations(desinations) {}

   private:
    bool find_next_customer(int& direction, Point& target) {
        const int dx[4] = {0, 1, 0, -1};
        const int dy[4] = {1, 0, -1, 0};

        priority_queue<Data> pq;
        vector<vector<bool>> is_visited(n, vector<bool>(n, false));
        pq.push({0, point});
        is_visited[point.x][point.y] = true;

        while (!pq.empty()) {
            Data cur = pq.top();
            pq.pop();

            if (map[cur.point.x][cur.point.y] == 2) {
                direction = cur.direction;
                target = cur.point;
                return true;
            }

            for (int i = 0; i < 4; i++) {
                Data next(cur.direction + 1,
                          {cur.point.x + dx[i], cur.point.y + dy[i]});

                if (next.point.x < 0 || next.point.x >= n || next.point.y < 0 ||
                    next.point.y >= n || map[next.point.x][next.point.y] == 1 ||
                    is_visited[next.point.x][next.point.y])
                    continue;

                pq.push(next);
                is_visited[next.point.x][next.point.y] = true;
            }
        }

        return false;
    }

    bool drive(int& direction, const Point& start, const Point& desination) {
        map[start.x][start.y] = 0;

        const int dx[4] = {0, 1, 0, -1};
        const int dy[4] = {1, 0, -1, 0};

        priority_queue<Data> pq;
        vector<vector<bool>> is_visited(n, vector<bool>(n, false));
        pq.push({0, start});
        is_visited[start.x][start.y] = true;

        while (!pq.empty()) {
            Data cur = pq.top();
            pq.pop();

            if (cur.point == desination) {
                direction = cur.direction;
                return true;
            }

            for (int i = 0; i < 4; i++) {
                Data next(cur.direction + 1,
                          {cur.point.x + dx[i], cur.point.y + dy[i]});

                if (next.point.x < 0 || next.point.x >= n || next.point.y < 0 ||
                    next.point.y >= n || map[next.point.x][next.point.y] == 1 ||
                    is_visited[next.point.x][next.point.y])
                    continue;

                pq.push(next);
                is_visited[next.point.x][next.point.y] = true;
            }
        }

        return false;
    }

    void shutdown_taxi() { fuel = -1; }

   public:
    void ride_all_customer() {
        for (int i = 0; i < m; i++) {
            int direction;
            Point target;

            // 다음 승객을 찾을 수 없으면 종료
            if (!find_next_customer(direction, target)) {
                shutdown_taxi();
                return;
            }

            // 승객이 있는 곳까지 갈 연료가 부족하면 종료
            if (direction > fuel) {
                shutdown_taxi();
                return;
            }
            fuel -= direction;

            Point destination = desinations[target.x][target.y];

            // 목적지까지 이동할 수 없으면 종료
            if (!drive(direction, target, destination)) {
                shutdown_taxi();
                return;
            }

            // 목적지까지 갈 연료가 부족하면 종료
            if (direction > fuel) {
                shutdown_taxi();
                return;
            }
            fuel -= direction;

            point = destination;
            fuel += direction * 2;
        }
    }

    int get_fuel() { return fuel; }
};

int main() {
    FASTIO();
    int N, M, init_fuel, r, c, r1, c1, r2, c2;
    cin >> N >> M >> init_fuel;

    vector<vector<int>> map(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> map[i][j];

    cin >> r >> c;
    vector<vector<Point>> desinations(N, vector<Point>(N));
    for (int i = 0; i < M; i++) {
        cin >> r1 >> c1 >> r2 >> c2;
        map[r1 - 1][c1 - 1] = 2;
        desinations[r1 - 1][c1 - 1] = {r2 - 1, c2 - 1};
    }

    Taxi taxi(N, M, init_fuel, {r - 1, c - 1}, map, desinations);
    taxi.ride_all_customer();
    cout << taxi.get_fuel() << "\n";

    return 0;
}