#include <cmath>
#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int N, M, k, x1 = -1, y1;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> k;
            if (k == 1) {
                if (x1 == -1)
                    x1 = i, y1 = j;
                else
                    cout << abs(i - x1) + abs(j - y1) << "\n";
            }
        }
    }

    return 0;
}