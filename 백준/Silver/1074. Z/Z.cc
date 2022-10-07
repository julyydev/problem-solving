// https://www.acmicpc.net/problem/1074
// written by julyy

#include <iostream>
using namespace std;
int n, r, c, d, m;

int z(int start, int size, int r, int c) {
    if (size == 1)
        return start + 2 * r + c;
    d >>= 1;
    m = 2 * (r / d) + (c / d);
    return z(start + (1 << 2 * size - 2) * m, size - 1, r % d, c % d);
}

int main() {
    cin >> n >> r >> c;
    d = 1 << n;
    cout << z(0, n, r, c);
    
    return 0;
}
