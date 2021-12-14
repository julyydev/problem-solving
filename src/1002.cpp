// https://www.acmicpc.net/problem/1002
// written by julyy

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T, x1, y1, r1, x2, y2, r2;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        double d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
     
        if (x1 == x2 && y1 == y2) {
            if (r1 == r2)
                cout << -1 << '\n';
            else
                cout << 0 << '\n';
        }
        else {
            if (r1 + r2 == d)
                cout << 1 << '\n';
            else if (r1 + r2 < d)
                cout << 0 << '\n';
            else {
                if (max(r1, r2) - min(r1, r2) < d)
                    cout << 2 << '\n';
                else if (max(r1, r2) - min(r1, r2) == d)
                    cout << 1 << '\n';
                else
                    cout << 0 << '\n';
            }
        }
    }

    return 0;
}
