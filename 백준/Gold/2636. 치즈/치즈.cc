#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

class Cheese {
    int r, c;
    vector<vector<int>> pieces;
    int time = 0;
    int piece_num = 0;

   public:
    Cheese() {}

   private:
    int bfs() {
        const int dx[4] = {0, 0, 1, -1};
        const int dy[4] = {1, -1, 0, 0};

        queue<Point> q;
        vector<vector<bool>> is_visited(r, vector<bool>(c, false));

        q.push({0, 0});
        is_visited[0][0] = true;

        int melted_piece_num = 0;

        while (!q.empty()) {
            Point cur = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                Point next(cur.x + dx[i], cur.y + dy[i]);
                if (next.x < 0 || next.x >= r || next.y < 0 || next.y >= c ||
                    is_visited[next.x][next.y])
                    continue;

                is_visited[next.x][next.y] = true;

                if (pieces[next.x][next.y] == 1) {
                    pieces[next.x][next.y] = 0;
                    melted_piece_num++;
                } else {
                    q.push(next);
                }
            }
        }

        return melted_piece_num;
    }

   public:
    void init() {
        cin >> r >> c;
        pieces.resize(r, vector<int>(c, 0));

        int x;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> x;
                if (x == 1) {
                    pieces[i][j] = 1;
                    piece_num++;
                }
            }
        }
    }

    void melt() {
        while (1) {
            time++;
            int melted_piece_num = bfs();

            if (piece_num == melted_piece_num) break;
            piece_num -= melted_piece_num;
        }
    }

    int get_time() { return time; }

    int get_prev_piece_num() { return piece_num; }
};

int main() {
    FASTIO();
    Cheese cheese;
    cheese.init();
    cheese.melt();
    cout << cheese.get_time() << "\n";
    cout << cheese.get_prev_piece_num() << "\n";

    return 0;
}