#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

vector<vector<int>> vec;

bool isAllSame(int x, int y, int n, int bit) {
    bool isSame = true;
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (vec[i][j] != bit) {
                isSame = false;
                break;
            }
        }
    }

    return isSame;
}

void recursion(int x, int y, int n) {
    int bit = vec[x][y];
    if (n == 1 || isAllSame(x, y, n, bit)) {
        cout << bit;
        return;
    }

    cout << "(";
    recursion(x, y, n / 2);
    recursion(x, y + n / 2, n / 2);
    recursion(x + n / 2, y, n / 2);
    recursion(x + n / 2, y + n / 2, n / 2);
    cout << ")";
}

int main() {
    FASTIO();
    int N;
    string s;
    cin >> N;
    vec.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < N; j++) vec[i][j] = s[j] - '0';
    }

    recursion(0, 0, N);

    return 0;
}