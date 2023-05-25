#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

class Board {
    int n;
    vector<vector<int>> board;

   public:
    Board() {}
    Board(int N, vector<vector<int>> init_board) : n(N), board(init_board) {}

    void moveUp() {
        for (int i = 0; i < n; i++) {
            vector<int> newLine(n, 0);

            int count = 0;
            for (int j = 0; j < n; j++) {
                if (board[j][i] == 0) continue;
                newLine[count++] = board[j][i];
            }

            for (int j = 0; j < n; j++) board[j][i] = 0;

            count = 0;
            for (int j = 0; j < n; j++) {
                if (j == n - 1) {
                    board[count++][i] = newLine[j];
                    break;
                }

                if (newLine[j] == newLine[j + 1]) {
                    board[count++][i] = 2 * newLine[j];
                    j++;
                } else {
                    board[count++][i] = newLine[j];
                }
            }
        }
    }

    void moveDown() {
        for (int i = 0; i < n; i++) {
            vector<int> newLine(n, 0);

            int count = n - 1;
            for (int j = n - 1; j >= 0; j--) {
                if (board[j][i] == 0) continue;
                newLine[count--] = board[j][i];
            }

            for (int j = n - 1; j >= 0; j--) board[j][i] = 0;

            count = n - 1;
            for (int j = n - 1; j >= 0; j--) {
                if (j == 0) {
                    board[count--][i] = newLine[j];
                    break;
                }

                if (newLine[j] == newLine[j - 1]) {
                    board[count--][i] = 2 * newLine[j];
                    j--;
                } else {
                    board[count--][i] = newLine[j];
                }
            }
        }
    }

    void moveLeft() {
        for (int i = 0; i < n; i++) {
            vector<int> newLine(n, 0);

            int count = 0;
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 0) continue;
                newLine[count++] = board[i][j];
            }

            for (int j = 0; j < n; j++) board[i][j] = 0;

            count = 0;
            for (int j = 0; j < n; j++) {
                if (j == n - 1) {
                    board[i][count++] = newLine[j];
                    break;
                }

                if (newLine[j] == newLine[j + 1]) {
                    board[i][count++] = 2 * newLine[j];
                    j++;
                } else {
                    board[i][count++] = newLine[j];
                }
            }
        }
    }

    void moveRight() {
        for (int i = 0; i < n; i++) {
            vector<int> newLine(n, 0);

            int count = n - 1;
            for (int j = n - 1; j >= 0; j--) {
                if (board[i][j] == 0) continue;
                newLine[count--] = board[i][j];
            }

            for (int j = n - 1; j >= 0; j--) board[i][j] = 0;

            count = n - 1;
            for (int j = n - 1; j >= 0; j--) {
                if (j == 0) {
                    board[i][count--] = newLine[j];
                    break;
                }

                if (newLine[j] == newLine[j - 1]) {
                    board[i][count--] = 2 * newLine[j];
                    j--;
                } else {
                    board[i][count--] = newLine[j];
                }
            }
        }
    }

    void print() {  // TEST:
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    int getMaxNumber() {
        int max = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (board[i][j] > max) max = board[i][j];

        return max;
    }
};

void backtracking(Board board, int& m, int t) {
    if (t == 5) {
        m = max(m, board.getMaxNumber());
        return;
    }

    Board temp = board;
    temp.moveUp();
    backtracking(temp, m, t + 1);

    temp = board;
    temp.moveDown();
    backtracking(temp, m, t + 1);

    temp = board;
    temp.moveLeft();
    backtracking(temp, m, t + 1);

    temp = board;
    temp.moveRight();
    backtracking(temp, m, t + 1);
}

int main() {
    FASTIO();
    int N;
    cin >> N;
    vector<vector<int>> init_board(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> init_board[i][j];
        }
    }

    Board board(N, init_board);
    int max = 0;
    backtracking(board, max, 0);
    cout << max << "\n";

    return 0;
}