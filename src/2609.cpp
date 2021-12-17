// https://www.acmicpc.net/problem/2609
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
    int m, n, g;
    cin >> m >> n;
    g = gcd(m, n);
    cout << g << '\n';
    cout << m * n / g << '\n';
    
    return 0;
}
