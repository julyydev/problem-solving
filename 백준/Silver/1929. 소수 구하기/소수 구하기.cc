// https://www.acmicpc.net/problem/1929
// written by julyy

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N;
    cin >> M >> N;
    bool isPrime;

    for (int i = M; i <= N; i++) {
        isPrime = true;
        if (i == 1)
            isPrime = false;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
            cout << i << '\n';
    }

    return 0;
}