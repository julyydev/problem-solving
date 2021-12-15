// https://www.acmicpc.net/problem/2447
// written by julyy

#include <iostream>
#include <cstring>
using namespace std;

void star_pattern(char **arr, int start_x, int start_y, int n) {
    if (n == 1)
        return;

    for (int i = start_x + n / 3; i < start_x + 2 * n / 3; i++) {
        for (int j = start_y + n / 3; j < start_y + 2 * n / 3; j++) {
            arr[i][j] = ' ';
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i != 1 || j != 1)
                star_pattern(arr, start_x + i * n / 3, start_y + j * n / 3, n / 3);
        }
    }
}

int main() {
    int N;
    cin >> N;

    char **star = new char*[N];
    for (int i = 0; i < N; i++) {
        star[i] = new char[N];
        memset(star[i], '*', sizeof(char) * N);
    }

    star_pattern(star, 0, 0, N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << star[i][j];
        }
        cout << '\n';
    }

    for (int i = 0; i < N; i++) {
        delete [] star[i];
    }
    delete [] star;

    return 0;
}
