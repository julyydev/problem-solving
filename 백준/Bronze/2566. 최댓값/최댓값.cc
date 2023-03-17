#include <iostream>
using namespace std;

int main() {
    int x, r, c, max = -1;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> x;
            if (x > max) max = x, r = i, c = j;
        }
    }

    cout << max << "\n" << r + 1 << " " << c + 1 << "\n";

    return 0;
}