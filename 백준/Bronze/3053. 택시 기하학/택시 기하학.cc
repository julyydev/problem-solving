// https://www.acmicpc.net/problem/3053
// written by julyy

#include <iostream>
using namespace std;

const double PI = 3.14159265358979;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int radius;
    cin >> radius;

    cout << fixed;
    cout.precision(6);
    cout << (double)PI * radius * radius << '\n';
    cout << (double)2 * radius * radius << '\n';

    return 0;
}
