#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

void recursion(int x, int y, int n, vector<vector<bool>>& star) {
    if (n == 3) {
        star[x][y] = star[x + 1][y - 1] = star[x + 1][y + 1] =
            star[x + 2][y - 2] = star[x + 2][y - 1] = star[x + 2][y] =
                star[x + 2][y + 1] = star[x + 2][y + 2] = true;
        return;
    }

    recursion(x, y, n / 2, star);
    recursion(x + n / 2, y - n / 2, n / 2, star);
    recursion(x + n / 2, y + n / 2, n / 2, star);
}

int main() {
    FASTIO();
    int N;
    cin >> N;
    vector<vector<bool>> star(N, vector<bool>(2 * N - 1, false));
    recursion(0, N - 1, N, star);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2 * N - 1; j++) cout << (star[i][j] ? "*" : " ");
        cout << "\n";
    }

    return 0;
}