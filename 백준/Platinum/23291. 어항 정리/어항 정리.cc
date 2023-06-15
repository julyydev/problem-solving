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

class Wizzard {
    int n;
    vector<vector<int>> fishbowls;

   public:
    Wizzard(int n, vector<int> init_fishbowls) : n(n) {
        fishbowls.assign(n, vector<int>(n, 0));
        fishbowls[n - 1] = init_fishbowls;
    }

   private:
    vector<vector<int>> rotate_matrix(const vector<vector<int>>& matrix, int r,
                                      int c) {
        vector<vector<int>> result(c, vector<int>(r));
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) result[j][r - i - 1] = matrix[i][j];

        return result;
    }

    void add_fish() {
        int min = 100000;
        for (const int& fish : fishbowls[n - 1])
            if (fish < min) min = fish;

        for (int& fish : fishbowls[n - 1])
            if (fish == min) fish++;
    }

    void adjust_fishbowls(Point start) {
        const int dx[2] = {0, 1};
        const int dy[2] = {1, 0};

        vector<vector<int>> change(n, vector<int>(n, 0));
        vector<vector<bool>> is_visited(n, vector<bool>(n, false));
        queue<Point> q;
        q.push(start);
        is_visited[start.x][start.y] = true;

        while (!q.empty()) {
            Point cur = q.front();
            q.pop();

            for (int i = 0; i < 2; i++) {
                Point next(cur.x + dx[i], cur.y + dy[i]);
                if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= n ||
                    fishbowls[next.x][next.y] == 0)
                    continue;

                Point large, small;
                if (fishbowls[cur.x][cur.y] >= fishbowls[next.x][next.y])
                    large = cur, small = next;
                else
                    large = next, small = cur;
                int d = (fishbowls[large.x][large.y] -
                         fishbowls[small.x][small.y]) /
                        5;
                change[large.x][large.y] -= d;
                change[small.x][small.y] += d;

                if (is_visited[next.x][next.y]) continue;
                q.push(next);
                is_visited[next.x][next.y] = true;
            }
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) fishbowls[i][j] += change[i][j];
    }

    void put_in_row_fishbowls() {
        vector<int> new_fishbowls(n);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (fishbowls[n - 1][i] == 0) continue;

            for (int j = n - 1; j >= 0; j--) {
                if (fishbowls[j][i] == 0) break;
                new_fishbowls[count++] = fishbowls[j][i];
                fishbowls[j][i] = 0;
            }
        }
        fishbowls[n - 1] = new_fishbowls;
    }

    void arrange_phase1() {
        Point target(n - 1, 0);
        int r = 1, c = 1;
        bool check = true;

        while (n - target.y - c >= r) {
            Point center(target.x + r - 1, target.y + c);

            vector<vector<int>> matrix(r, vector<int>(c));
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    matrix[i][j] = fishbowls[target.x + i][target.y + j];
                    fishbowls[target.x + i][target.y + j] = 0;
                }
            }

            vector<vector<int>> rotated_matrix = rotate_matrix(matrix, r, c);
            for (int i = 0; i < c; i++)
                for (int j = 0; j < r; j++)
                    fishbowls[center.x + i - c][center.y + j] =
                        rotated_matrix[i][j];

            target = {center.x - c, center.y};
            if (check)
                r++;
            else
                c++;
            check = !check;
        }

        adjust_fishbowls(target);
        put_in_row_fishbowls();
    }

    void arrange_phase2() {
        Point target(n - 1, 0);
        int r = 1, c = n / 2, t = 0;

        while (t++ < 2) {
            Point center(target.x + r - 1, target.y + c);

            vector<vector<int>> matrix(r, vector<int>(c));
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    matrix[i][j] = fishbowls[target.x + i][target.y + j];
                    fishbowls[target.x + i][target.y + j] = 0;
                }
            }

            vector<vector<int>> rotated_matrix = rotate_matrix(matrix, r, c);
            vector<vector<int>> twice_rotated_matrix =
                rotate_matrix(rotated_matrix, c, r);
            for (int i = 0; i < r; i++)
                for (int j = 0; j < c; j++)
                    fishbowls[center.x + i - (2 * t - 1)][center.y + j] =
                        twice_rotated_matrix[i][j];

            target = {center.x - r, center.y};
            r *= 2, c /= 2;
        }

        adjust_fishbowls({n - 4, 3 * n / 4});
        put_in_row_fishbowls();
    }

   public:
    int get_fish_diff() {
        int max = 0, min = 100000;
        for (const int& fish : fishbowls[n - 1]) {
            if (fish > max) max = fish;
            if (fish < min) min = fish;
        }

        return max - min;
    }

    void arrange_fishbowls() {
        add_fish();
        arrange_phase1();
        arrange_phase2();
    }
};

int main() {
    FASTIO();
    int N, K;
    cin >> N >> K;

    vector<int> init_fishbowls(N);
    for (int i = 0; i < N; i++) cin >> init_fishbowls[i];
    Wizzard wizzard(N, init_fishbowls);

    int count = 0;
    while (wizzard.get_fish_diff() > K) {
        wizzard.arrange_fishbowls();
        count++;
    }
    cout << count << "\n";

    return 0;
}