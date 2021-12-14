// https://www.acmicpc.net/problem/1085
// written by julyy

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y, w, h;
    cin >> x >> y >> w >> h;

    cout << min(min(x, y), min(w - x, h - y));

    return 0;
}
