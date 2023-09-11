#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

enum Cell {
    WALL,
    CLEANED,
    NOT_CLEANED,
};

struct Point {
    int x, y;

    Point() {}
    Point(int x, int y) : x(x), y(y) {}
};

class Cleaner {
    int n, m;
    vector<vector<Cell>> map;
    Point point;
    int direction;
    int cleaned_num;

   public:
    Cleaner() {}

    void init() {
        cin >> n >> m;
        map.resize(n, vector<Cell>(m));

        int r, c, d;
        cin >> r >> c >> d;
        point = {r, c};
        direction = d;

        int x;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> x;

                switch (x) {
                    case 0:
                        map[i][j] = Cell::NOT_CLEANED;
                        break;

                    case 1:
                        map[i][j] = Cell::WALL;
                        break;
                }
            }
        }

        cleaned_num = 0;
    }

    void cleaning() {
        const int dx[4] = {-1, 0, 1, 0};
        const int dy[4] = {0, 1, 0, -1};

        while (1) {
            if (map[point.x][point.y] == Cell::NOT_CLEANED) {
                map[point.x][point.y] = Cell::CLEANED;
                cleaned_num++;
            }

            bool has_not_cleaned = false;
            for (int i = 0; i < 4; i++) {
                direction = (direction + 3) % 4;
                Point next(point.x + dx[direction], point.y + dy[direction]);

                if (map[next.x][next.y] == Cell::NOT_CLEANED) {
                    point = next;
                    has_not_cleaned = true;
                    break;
                }
            }
            if (has_not_cleaned) continue;

            int back_direction = (direction + 2) % 4;
            Point back(point.x + dx[back_direction],
                       point.y + dy[back_direction]);
            if (map[back.x][back.y] == Cell::WALL) return;
            point = back;
        }
    }

    int get_cleaned_num() { return cleaned_num; }
};

int main() {
    FASTIO();

    Cleaner cleaner;
    cleaner.init();
    cleaner.cleaning();
    cout << cleaner.get_cleaned_num() << "\n";

    return 0;
}