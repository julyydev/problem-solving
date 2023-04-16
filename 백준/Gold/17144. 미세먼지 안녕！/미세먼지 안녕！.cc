#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

class Room {
    vector<vector<int>> map;
    int r, c;
    int purifier_position;

   public:
    Room(vector<vector<int>> init_map, int r, int c, int purifier_position)
        : map(init_map), r(r), c(c), purifier_position(purifier_position) {}
    void spreadFineDust() {
        vector<vector<int>> new_map(r, vector<int>(c, 0));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (map[i][j] == 0) continue;
                if (map[i][j] == -1) {
                    new_map[i][j] = -1;
                    continue;
                }

                int amount = map[i][j] / 5, count = 0;
                for (int k = 0; k < 4; k++) {
                    int next_x = i + dx[k], next_y = j + dy[k];
                    if (next_x < 0 || next_x >= r || next_y < 0 ||
                        next_y >= c || map[next_x][next_y] == -1)
                        continue;

                    new_map[next_x][next_y] += amount;
                    count++;
                }
                new_map[i][j] += map[i][j] - amount * count;
            }
        }
        map = new_map;
    }
    void runAirPurifier() {
        // 위쪽, 반시계 방향
        for (int i = purifier_position - 1; i > 0; i--)
            map[i][0] = map[i - 1][0];
        for (int i = 0; i < c - 1; i++) map[0][i] = map[0][i + 1];
        for (int i = 0; i < purifier_position; i++)
            map[i][c - 1] = map[i + 1][c - 1];
        for (int i = c - 1; i > 1; i--)
            map[purifier_position][i] = map[purifier_position][i - 1];
        map[purifier_position][1] = 0;

        // 아래쪽, 시계 방향
        for (int i = purifier_position + 2; i < r - 1; i++)
            map[i][0] = map[i + 1][0];
        for (int i = 0; i < c - 1; i++) map[r - 1][i] = map[r - 1][i + 1];
        for (int i = r - 1; i > purifier_position + 1; i--)
            map[i][c - 1] = map[i - 1][c - 1];
        for (int i = c - 1; i > 1; i--)
            map[purifier_position + 1][i] = map[purifier_position + 1][i - 1];
        map[purifier_position + 1][1] = 0;
    }
    int getNumberOfDust() {
        int sum = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (map[i][j] == -1) continue;
                sum += map[i][j];
            }
        }
        return sum;
    }
};

int main() {
    FASTIO();
    int R, C, T;
    cin >> R >> C >> T;

    vector<vector<int>> init_map(R, vector<int>(C));
    int purifier_position = 0;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) {
            cin >> init_map[i][j];
            if (init_map[i][j] == -1 && purifier_position == 0)
                purifier_position = i;
        }

    Room room(init_map, R, C, purifier_position);
    while (T--) {
        room.spreadFineDust();
        room.runAirPurifier();
    }
    cout << room.getNumberOfDust() << "\n";

    return 0;
}