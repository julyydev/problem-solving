// https://www.acmicpc.net/problem/11758
// written by julyy

#include <iostream>
using namespace std;

int main() {
    int x1, x2, x3, y1, y2, y3, res;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    res = x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1;

    if (res > 0)
        cout << 1;
    else if (res < 0)
        cout << -1;
    else
        cout << 0;

    return 0;
}
