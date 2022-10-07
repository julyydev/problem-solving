// https://www.acmicpc.net/problem/1011
// written by julyy

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        long long x, y;
        cin >> x >> y;
        long long d = y - x;
        long long k = ceil(sqrt(d));
        
        if (d <= k * (k - 1))
            cout << 2 * k - 2 << '\n';
        else
            cout << 2 * k - 1 << '\n';
    }

    return 0;
}
