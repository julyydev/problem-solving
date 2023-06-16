#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

bool is_possible(const vector<vector<int>>& sudoku, int x, int y, int target) {
    for (int i = 0; i < 9; i++) {
        if (sudoku[x][i] == target) return false;
        if (sudoku[i][y] == target) return false;
    }

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            if (sudoku[3 * (x / 3) + i][3 * (y / 3) + j] == target)
                return false;
        }

    return true;
}

void backtracking(vector<vector<int>> sudoku, int index, bool& check) {
    if (check) return;

    if (index == 81) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) cout << sudoku[i][j];
            cout << "\n";
        }
        check = true;
        return;
    }

    int x = index / 9, y = index % 9;
    if (sudoku[x][y] != 0)
        backtracking(sudoku, index + 1, check);
    else {
        for (int i = 1; i <= 9; i++) {
            if (!is_possible(sudoku, x, y, i)) continue;
            sudoku[x][y] = i;
            backtracking(sudoku, index + 1, check);
            sudoku[x][y] = 0;
        }
    }
    return;
}

int main() {
    FASTIO();
    vector<vector<int>> sudoku(9, vector<int>(9));
    string s;
    for (int i = 0; i < 9; i++) {
        cin >> s;
        for (int j = 0; j < 9; j++) sudoku[i][j] = s[j] - '0';
    }

    bool check = false;
    backtracking(sudoku, 0, check);

    return 0;
}