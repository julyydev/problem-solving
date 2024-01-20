#include <iostream>
#include <vector>
using namespace std;

class MonominoDomino {
    int score = 0;
    vector<vector<bool>> green_board;
    vector<vector<bool>> blue_board;

   public:
    MonominoDomino() {
        green_board.resize(6, vector<bool>(4, false));
        blue_board.resize(6, vector<bool>(4, false));
    }

    void put_block(int t, int x, int y) {
        switch (t) {
            case 1: {
                int i;
                for (i = 0; i < 6; i++) {
                    if (green_board[i][y]) break;
                }
                green_board[--i][y] = true;

                if (green_board[i][0] && green_board[i][1] &&
                    green_board[i][2] && green_board[i][3]) {
                    for (int j = i; j > 0; j--)
                        green_board[j] = green_board[j - 1];
                    green_board[0].assign(4, false);
                    score++;
                }

                for (i = 0; i < 6; i++) {
                    if (blue_board[i][x]) break;
                }
                blue_board[--i][x] = true;

                if (blue_board[i][0] && blue_board[i][1] && blue_board[i][2] &&
                    blue_board[i][3]) {
                    for (int j = i; j > 0; j--)
                        blue_board[j] = blue_board[j - 1];
                    blue_board[0].assign(4, false);
                    score++;
                }

                break;
            }
            case 2: {
                int i;
                for (i = 0; i < 6; i++) {
                    if (green_board[i][y] || green_board[i][y + 1]) break;
                }
                i--;
                green_board[i][y] = green_board[i][y + 1] = true;

                if (green_board[i][0] && green_board[i][1] &&
                    green_board[i][2] && green_board[i][3]) {
                    for (int j = i; j > 0; j--)
                        green_board[j] = green_board[j - 1];
                    green_board[0].assign(4, false);
                    score++;
                }

                for (i = 1; i < 6; i++) {
                    if (blue_board[i][x]) break;
                }
                i--;
                blue_board[i][x] = blue_board[i - 1][x] = true;

                if (blue_board[i][0] && blue_board[i][1] && blue_board[i][2] &&
                    blue_board[i][3]) {
                    for (int j = i; j > 0; j--)
                        blue_board[j] = blue_board[j - 1];
                    blue_board[0].assign(4, false);
                    score++;
                }

                if (blue_board[i - 1][0] && blue_board[i - 1][1] &&
                    blue_board[i - 1][2] && blue_board[i - 1][3]) {
                    for (int j = i - 1; j > 0; j--)
                        blue_board[j] = blue_board[j - 1];
                    blue_board[0].assign(4, false);
                    score++;
                }

                if (blue_board[i][0] && blue_board[i][1] && blue_board[i][2] &&
                    blue_board[i][3]) {
                    for (int j = i; j > 0; j--)
                        blue_board[j] = blue_board[j - 1];
                    blue_board[0].assign(4, false);
                    score++;
                }

                break;
            }
            case 3: {
                int i;
                for (i = 1; i < 6; i++) {
                    if (green_board[i][y]) break;
                }
                i--;
                green_board[i][y] = green_board[i - 1][y] = true;

                if (green_board[i][0] && green_board[i][1] &&
                    green_board[i][2] && green_board[i][3]) {
                    for (int j = i; j > 0; j--)
                        green_board[j] = green_board[j - 1];
                    green_board[0].assign(4, false);
                    score++;
                }

                if (green_board[i - 1][0] && green_board[i - 1][1] &&
                    green_board[i - 1][2] && green_board[i - 1][3]) {
                    for (int j = i - 1; j > 0; j--)
                        green_board[j] = green_board[j - 1];
                    green_board[0].assign(4, false);
                    score++;
                }

                if (green_board[i][0] && green_board[i][1] &&
                    green_board[i][2] && green_board[i][3]) {
                    for (int j = i; j > 0; j--)
                        green_board[j] = green_board[j - 1];
                    green_board[0].assign(4, false);
                    score++;
                }

                for (i = 0; i < 6; i++) {
                    if (blue_board[i][x] || blue_board[i][x + 1]) break;
                }
                i--;
                blue_board[i][x] = blue_board[i][x + 1] = true;

                if (blue_board[i][0] && blue_board[i][1] && blue_board[i][2] &&
                    blue_board[i][3]) {
                    for (int j = i; j > 0; j--)
                        blue_board[j] = blue_board[j - 1];
                    blue_board[0].assign(4, false);
                    score++;
                }

                break;
            }
        }

        if (green_board[0][0] || green_board[0][1] || green_board[0][2] ||
            green_board[0][3]) {
            for (int i = 3; i >= 0; i--) green_board[i + 2] = green_board[i];
            green_board[1].assign(4, false);
            green_board[0].assign(4, false);
        }

        if (green_board[1][0] || green_board[1][1] || green_board[1][2] ||
            green_board[1][3]) {
            for (int i = 4; i >= 0; i--) green_board[i + 1] = green_board[i];
            green_board[0].assign(4, false);
        }

        if (blue_board[0][0] || blue_board[0][1] || blue_board[0][2] ||
            blue_board[0][3]) {
            for (int i = 3; i >= 0; i--) blue_board[i + 2] = blue_board[i];
            blue_board[1].assign(4, false);
            blue_board[0].assign(4, false);
        }

        if (blue_board[1][0] || blue_board[1][1] || blue_board[1][2] ||
            blue_board[1][3]) {
            for (int i = 4; i >= 0; i--) blue_board[i + 1] = blue_board[i];
            blue_board[0].assign(4, false);
        }
    }

    int get_score() { return score; }

    int get_count() {
        int count = 0;

        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 4; j++) {
                if (green_board[i][j]) count++;
                if (blue_board[i][j]) count++;
            }
        }

        return count;
    }
};

int main() {
    int n, t, x, y;
    cin >> n;

    MonominoDomino monomin_domino;
    while (n--) {
        cin >> t >> x >> y;
        monomin_domino.put_block(t, x, y);
    }
    cout << monomin_domino.get_score() << "\n";
    cout << monomin_domino.get_count() << "\n";

    return 0;
}
