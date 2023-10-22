#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

const int dx[3] = {-1, 0, 1};
const int dy[3] = {1, 1, 1};

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

class Bakery {
    int r, c;
    vector<vector<bool>> map;

   public:
    Bakery() {}

   private:
    bool dfs(Point cur) {
        if (cur.y == c - 1) return true;

        for (int i = 0; i < 3; i++) {
            Point next(cur.x + dx[i], cur.y + dy[i]);
            if (next.x < 0 || next.x >= r || next.y < 0 || next.y >= c ||
                !map[next.x][next.y])
                continue;

            map[next.x][next.y] = false;
            if (dfs(next)) return true;
        }

        return false;
    }

   public:
    void init() {
        cin >> r >> c;
        map.resize(r, vector<bool>(c, false));

        char x;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> x;
                if (x == '.') map[i][j] = true;
            }
        }
    }

    int get_pipeline_num() {
        int count = 0;
        for (int i = 0; i < r; i++)
            if (dfs({i, 0})) count++;

        return count;
    }
};

int main() {
    FASTIO();
    Bakery bakery;
    bakery.init();
    cout << bakery.get_pipeline_num() << "\n";

    return 0;
}