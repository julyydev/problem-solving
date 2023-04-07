#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

class Wizard {
    vector<vector<int>> ice;
    const int size;

   public:
    Wizard(vector<vector<int>> init_ice, int size)
        : ice(init_ice), size(size) {}

   private:
    void rotate(int x, int y, int l) {
        vector<vector<int>> temp(1 << l, vector<int>(1 << l));
        for (int i = 0; i < (1 << l); i++)
            for (int j = 0; j < (1 << l); j++)
                temp[j][(1 << l) - i - 1] = ice[x + i][y + j];

        for (int i = 0; i < (1 << l); i++)
            for (int j = 0; j < (1 << l); j++) ice[x + i][y + j] = temp[i][j];
    }
    bool isMelt(Point point) {
        if (ice[point.x][point.y] == 0) return false;

        int nearIce = 0;
        for (int i = 0; i < 4; i++) {
            Point next(point.x + dx[i], point.y + dy[i]);
            if (next.x < 0 || next.x >= (1 << size) || next.y < 0 ||
                next.y >= (1 << size))
                continue;

            if (ice[next.x][next.y] > 0) nearIce++;
        }
        return nearIce < 3;
    }
    int bfs(const int& i, const int& j, vector<vector<bool>>& isVisited) {
        int count = 1;
        queue<Point> q;
        q.push({i, j});
        isVisited[i][j] = true;

        while (!q.empty()) {
            Point cur = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                Point next(cur.x + dx[i], cur.y + dy[i]);
                if (next.x < 0 || next.x >= (1 << size) || next.y < 0 ||
                    next.y >= (1 << size))
                    continue;

                if (!isVisited[next.x][next.y] && ice[next.x][next.y] > 0) {
                    count++;
                    q.push(next);
                    isVisited[next.x][next.y] = true;
                }
            }
        }

        return count;
    }

   public:
    void firestorm(int l) {
        for (int i = 0; i < (1 << (size - l)); i++) {
            for (int j = 0; j < (1 << (size - l)); j++) {
                rotate(i * (1 << l), j * (1 << l), l);
            }
        }

        vector<Point> meltingList;
        for (int i = 0; i < (1 << size); i++)
            for (int j = 0; j < (1 << size); j++)
                if (isMelt({i, j})) meltingList.push_back({i, j});

        for (auto melt : meltingList) ice[melt.x][melt.y]--;
    }
    int getTotalIce() {
        int sum = 0;
        for (int i = 0; i < (1 << size); i++)
            for (int j = 0; j < (1 << size); j++) sum += ice[i][j];
        return sum;
    }
    int getBiggestBlockSize() {
        int maxCount = 0;
        vector<vector<bool>> isVisited(1 << size,
                                       vector<bool>(1 << size, false));

        for (int i = 0; i < (1 << size); i++) {
            for (int j = 0; j < (1 << size); j++) {
                if (!isVisited[i][j] && ice[i][j] > 0) {
                    int count = bfs(i, j, isVisited);
                    if (count > maxCount) maxCount = count;
                }
            }
        }

        return maxCount;
    }
};

int main() {
    FASTIO();
    int N, Q, L;
    cin >> N >> Q;
    vector<vector<int>> init_ice((1 << N), vector<int>(1 << N));
    for (int i = 0; i < (1 << N); i++)
        for (int j = 0; j < (1 << N); j++) cin >> init_ice[i][j];

    Wizard wizard(init_ice, N);
    while (Q--) {
        cin >> L;
        wizard.firestorm(L);
    }
    cout << wizard.getTotalIce() << "\n";
    cout << wizard.getBiggestBlockSize() << "\n";

    return 0;
}