#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    int n = sqrt(y - x);
    if (n == 0) {
        cout << "0\n";
        return 0;
    }

    if (y - x == n * n) {
        cout << 2 * n - 1 << "\n";
    } else {
        if (y - x <= n * n + n)
            cout << 2 * n << "\n";
        else
            cout << 2 * n + 1 << "\n";
    }

    return 0;
}
