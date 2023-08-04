#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

const int dx[4] = {0, 0, -1, 1};  // 우, 좌, 상, 하
const int dy[4] = {1, -1, 0, 0};

struct Point {
    int x, y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
};

struct Heater {
    Point point;
    int direction;
    Heater(Point point, int direction) : point(point), direction(direction) {}
};

class GoodbyeHeater {
    int r, c, k;
    int chocolate;
    vector<vector<int>> temperatures;
    vector<Heater> heaters;
    vector<Point> need_to_checks;
    vector<vector<vector<bool>>> is_wall;

   public:
    GoodbyeHeater(int r, int c, int k, const vector<Point>& need_to_checks,
                  const vector<Heater>& heaters,
                  const vector<vector<vector<bool>>>& is_wall)
        : r(r),
          c(c),
          k(k),
          chocolate(0),
          need_to_checks(need_to_checks),
          heaters(heaters),
          is_wall(is_wall) {
        temperatures.assign(r, vector<int>(c, 0));
    }

   private:
    void spread_air(vector<vector<int>>& temp_temperatures, Point point,
                    const int& direction, int temperature) {  // recursion
        if (point.x < 0 || point.x >= r || point.y < 0 || point.y >= c ||
            temperature == 0)
            return;

        temp_temperatures[point.x][point.y] = temperature;

        if (direction == 0 || direction == 1) {  // 좌, 우
            if (point.x - 1 >= 0 && !is_wall[point.x - 1][point.y][direction] &&
                !is_wall[point.x][point.y][2]) {
                Point next(point.x - 1, point.y + dy[direction]);
                spread_air(temp_temperatures, next, direction, temperature - 1);
            }

            if (!is_wall[point.x][point.y][direction]) {
                Point next(point.x, point.y + dy[direction]);
                spread_air(temp_temperatures, next, direction, temperature - 1);
            }

            if (point.x + 1 < r && !is_wall[point.x + 1][point.y][direction] &&
                !is_wall[point.x][point.y][3]) {
                Point next(point.x + 1, point.y + dy[direction]);
                spread_air(temp_temperatures, next, direction, temperature - 1);
            }
        } else {  // 상, 하
            if (point.y - 1 >= 0 && !is_wall[point.x][point.y - 1][direction] &&
                !is_wall[point.x][point.y][1]) {
                Point next(point.x + dx[direction], point.y - 1);
                spread_air(temp_temperatures, next, direction, temperature - 1);
            }

            if (!is_wall[point.x][point.y][direction]) {
                Point next(point.x + dx[direction], point.y);
                spread_air(temp_temperatures, next, direction, temperature - 1);
            }

            if (point.y + 1 < c && !is_wall[point.x][point.y + 1][direction] &&
                !is_wall[point.x][point.y][0]) {
                Point next(point.x + dx[direction], point.y + 1);
                spread_air(temp_temperatures, next, direction, temperature - 1);
            }
        }
    }

    void come_out_air_of_all_heaters() {  // step.1
        for (const Heater& heater : heaters) {
            vector<vector<int>> temp_temperatures(r, vector<int>(c, 0));
            Point first(heater.point.x + dx[heater.direction],
                        heater.point.y + dy[heater.direction]);
            spread_air(temp_temperatures, first, heater.direction, 5);

            for (int i = 0; i < r; i++)
                for (int j = 0; j < c; j++)
                    temperatures[i][j] += temp_temperatures[i][j];
        }
    }
    void controll_temperature() {  // step.2
        vector<vector<int>> change_temperatures(r, vector<int>(c, 0));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c - 1; j++) {
                if (is_wall[i][j][0]) continue;

                int large, small;
                if (temperatures[i][j] >= temperatures[i][j + 1])
                    large = j, small = j + 1;
                else
                    large = j + 1, small = j;

                int change =
                    (temperatures[i][large] - temperatures[i][small]) / 4;
                change_temperatures[i][large] -= change;
                change_temperatures[i][small] += change;
            }
        }

        for (int i = 0; i < r - 1; i++) {
            for (int j = 0; j < c; j++) {
                if (is_wall[i][j][3]) continue;

                int large, small;
                if (temperatures[i][j] >= temperatures[i + 1][j])
                    large = i, small = i + 1;
                else
                    large = i + 1, small = i;

                int change =
                    (temperatures[large][j] - temperatures[small][j]) / 4;
                change_temperatures[large][j] -= change;
                change_temperatures[small][j] += change;
            }
        }

        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                temperatures[i][j] += change_temperatures[i][j];
    }
    void decrease_temperature_outer_compartment() {  // step.3
        for (int j = 0; j < c; j++) {
            if (temperatures[0][j] == 0) continue;
            temperatures[0][j]--;
        }

        for (int i = 1; i < r - 1; i++) {
            if (temperatures[i][0] == 0) continue;
            temperatures[i][0]--;
        }

        for (int i = 1; i < r - 1; i++) {
            if (temperatures[i][c - 1] == 0) continue;
            temperatures[i][c - 1]--;
        }

        for (int j = 0; j < c; j++) {
            if (temperatures[r - 1][j] == 0) continue;
            temperatures[r - 1][j]--;
        }
    }
    void eat_chocolate() {  // step.4
        chocolate++;
    }
    bool is_temperature_valid() {  // step.5
        for (const Point& point : need_to_checks)
            if (temperatures[point.x][point.y] < k) return false;
        return true;
    }

   public:
    void performance_test() {
        while (1) {
            come_out_air_of_all_heaters();
            controll_temperature();
            decrease_temperature_outer_compartment();
            eat_chocolate();

            if (is_temperature_valid()) return;
            if (chocolate == 100) {
                chocolate++;
                return;
            }
        }
    }

    int get_chocolate() { return chocolate; }
};

int main() {
    FASTIO();
    int R, C, K, W, x, y, t;
    cin >> R >> C >> K;
    vector<Point> need_to_checks;
    vector<Heater> heaters;
    vector<vector<vector<bool>>> is_wall(
        R, vector<vector<bool>>(C, vector<bool>(4, false)));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> x;

            if (x == 0) continue;

            if (x == 5)
                need_to_checks.push_back({i, j});
            else
                heaters.push_back({{i, j}, x - 1});
        }
    }

    cin >> W;
    for (int i = 0; i < W; i++) {
        cin >> x >> y >> t;
        if (t == 0) {
            is_wall[x - 1][y - 1][2] = true;
            is_wall[x - 2][y - 1][3] = true;
        } else {
            is_wall[x - 1][y - 1][0] = true;
            is_wall[x - 1][y][1] = true;
        }
    }

    GoodbyeHeater goodbyeHeater(R, C, K, need_to_checks, heaters, is_wall);
    goodbyeHeater.performance_test();
    cout << goodbyeHeater.get_chocolate() << "\n";

    return 0;
}
