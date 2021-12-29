// https://www.acmicpc.net/problem/1009
// written by julyy

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, a, b, mul;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> a >> b;
        mul = 1;
        while (b--) {
            mul *= a;
            mul %= 10;
        }
        mul == 0 ? cout << 10 << '\n' : cout << mul << '\n';
    }
    
    return 0;
}
