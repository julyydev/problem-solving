#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int negative, zero, positive;
vector<vector<int>> matrix;

bool isAllSame(int x, int y, int n, int value) {
    bool isSame = true;
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (matrix[i][j] != value) {
                isSame = false;
                break;
            }
        }
    }
    return isSame;
}

void check(int x, int y, int n) {
    int value = matrix[x][y];
    if (n == 1 || isAllSame(x, y, n, value)) {
        if (value == 1)
            positive++;
        else if (value == 0)
            zero++;
        else
            negative++;
        return;
    }

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) check(x + n * i / 3, y + n * j / 3, n / 3);
}

int main() {
    FASTIO();
    int N;
    cin >> N;
    matrix.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> matrix[i][j];

    check(0, 0, N);

    cout << negative << "\n";
    cout << zero << "\n";
    cout << positive << "\n";

    return 0;
}