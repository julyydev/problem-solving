#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    FASTIO();
    int T, M, N, x, y;
    cin >> T;

    while (T--) {
        cin >> M >> N >> x >> y;
        int max_year = M * N / gcd(M, N);

        int year = -1;
        for (int i = x; i <= max_year; i += M) {
            if (i % N == y || (i % N == 0 && N == y)) year = i;
        }
        cout << year << "\n";
    }

    return 0;
}