// https://www.acmicpc.net/problem/1934
// written by julyy

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (a == 0)
        return b;
    else if (b == 0)
        return a;
    if (a > b)
        return gcd(b, a % b);
    else
        return gcd(a, b % a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T, m, n, g;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> m >> n;
        g = gcd(m, n);
        cout << m * n / g << '\n';
    }
    
    return 0;
}
