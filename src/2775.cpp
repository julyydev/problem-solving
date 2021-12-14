// https://www.acmicpc.net/problem/2775
// written by julyy

#include <iostream>
using namespace std;

int people(int k, int n) {
    if (k == 0)
        return n;
    if (n == 1)
        return 1;
    return people(k - 1, n) + people(k, n - 1);
}

int main() {
    int T, k, n;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> k >> n;
        cout << people(k, n) << '\n';
    }

    return 0;
}
