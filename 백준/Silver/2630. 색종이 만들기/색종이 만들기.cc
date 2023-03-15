#include <cstring>
#include <iostream>
using namespace std;

int map[128][128];
int white, blue;

bool isAllSame(int x, int y, int n, int color) {
    bool isSame = true;
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (map[i][j] != color) {
                isSame = false;
                break;
            }
        }
    }
    return isSame;
}

void check(int x, int y, int n) {
    int color = map[x][y];  // 0: white, 1: blue
    if (n == 1 || isAllSame(x, y, n, color)) {
        if (color == 0)
            white++;
        else
            blue++;
        return;
    }

    check(x, y, n / 2);
    check(x + n / 2, y, n / 2);
    check(x, y + n / 2, n / 2);
    check(x + n / 2, y + n / 2, n / 2);
}

int main() {
    int N, c;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> c;
            map[i][j] = c;
        }
    }

    white = 0, blue = 0;
    check(0, 0, N);

    cout << white << "\n" << blue << "\n";

    return 0;
}