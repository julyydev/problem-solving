#include <algorithm>
#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

const int dr[8] = {0, -1, -1, -1, 0, 1, 1, 1};  // ←, ↖, ↑, ↗, →, ↘, ↓, ↙
const int dc[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

struct Point {
    int r, c;
    Point(int r, int c) : r(r), c(c) {}
};

class Wizzard {
    int n;
    vector<vector<int>> water;
    vector<Point> clouds;

   public:
    Wizzard(int n, vector<vector<int>> water) : n(n), water(water) {
        clouds.push_back({n - 1, 0});
        clouds.push_back({n - 1, 1});
        clouds.push_back({n - 2, 0});
        clouds.push_back({n - 2, 1});
    }

   private:
    void moveAllCloud(int d, int s) {
        for (Point& cloud : clouds) {
            cloud.r = (cloud.r + dr[d] * (s % n) + n) % n;
            cloud.c = (cloud.c + dc[d] * (s % n) + n) % n;
        }
    }
    void rain() {
        for (Point& cloud : clouds) {
            water[cloud.r][cloud.c]++;
        }
    }
    void disappearAllCloud() { clouds.clear(); }
    void duplicateWater() {
        for (Point& cloud : clouds) {
            int count = 0;
            for (int i = 0; i < 4; i++) {
                Point temp(cloud.r + dr[2 * i + 1], cloud.c + dc[2 * i + 1]);
                if (temp.r < 0 || temp.r >= n || temp.c < 0 || temp.c >= n ||
                    water[temp.r][temp.c] == 0)
                    continue;
                count++;
            }
            water[cloud.r][cloud.c] += count;
        }
    }
    void createCloud() {
        vector<Point> new_clouds;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (water[i][j] >= 2) {
                    bool is_check = false;
                    for (Point& cloud : clouds) {
                        if (cloud.r == i && cloud.c == j) {
                            is_check = true;
                            break;
                        }
                    }
                    if (is_check) continue;
                    new_clouds.push_back({i, j});
                    water[i][j] -= 2;
                }
            }
        }
        clouds = new_clouds;
    }

   public:
    void bibaragi(int d, int s) {
        moveAllCloud(d, s);  // step.1
        rain();              // step.2
        duplicateWater();    // step.4
        createCloud();       // step.3 & 5
    }
    int getTotalWater() {
        int sum = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) sum += water[i][j];
        return sum;
    }
};

int main() {
    FASTIO();
    int N, M, d, s;
    cin >> N >> M;
    vector<vector<int>> init_water(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> init_water[i][j];

    Wizzard wizzard(N, init_water);
    while (M--) {
        cin >> d >> s;
        wizzard.bibaragi(d - 1, s);
    }
    cout << wizzard.getTotalWater() << "\n";

    return 0;
}