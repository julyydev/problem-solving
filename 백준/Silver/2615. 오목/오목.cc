#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

const int dx[4] = {-1, 0, 1, 1};
const int dy[4] = {1, 1, 1, 0};

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

int main() {
    FASTIO();
    vector<vector<int>> board(19, vector<int>(19));

    for (int i = 0; i < 19; i++)
        for (int j = 0; j < 19; j++) cin >> board[i][j];

    for (int j = 0; j < 19; j++) {
        for (int i = 0; i < 19; i++) {
            if (board[i][j] == 0) continue;

            int color = board[i][j];

            for (int k = 0; k < 4; k++) {
                bool check = true;

                Point prev(i - dx[k], j - dy[k]);
                if (prev.x >= 0 && prev.x < 19 && prev.y >= 0 && prev.y < 19 &&
                    board[prev.x][prev.y] == color)
                    continue;

                for (int l = 1; l < 5; l++) {
                    Point next(i + l * dx[k], j + l * dy[k]);
                    if (next.x < 0 || next.x >= 19 || next.y < 0 ||
                        next.y >= 19 || board[next.x][next.y] != color) {
                        check = false;
                        break;
                    }
                }

                if (!check) continue;

                Point next(i + 5 * dx[k], j + 5 * dy[k]);
                if (next.x >= 0 && next.x < 19 && next.y >= 0 && next.y < 19 &&
                    board[next.x][next.y] == color) {
                    check = false;
                }

                if (check) {
                    cout << color << "\n";
                    cout << i + 1 << " " << j + 1 << "\n";
                    return 0;
                }
            }
        }
    }

    cout << "0\n";

    return 0;
}