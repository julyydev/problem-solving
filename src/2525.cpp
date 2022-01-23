// https://www.acmicpc.net/problem/2525
// written by julyy

#include <iostream>
using namespace std;

int main() {
    int h, m, t, time;
    cin >> h >> m >> t;
    time = h * 60 + m + t;
    cout << time / 60 % 24 << ' ' << time % 60;
    
    return 0;
}
