// https://www.acmicpc.net/problem/2702
// written by julyy

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        int g = gcd(a, b);
        cout << a * b / g << ' ' << g << '\n';
    }
    
    return 0;
}
