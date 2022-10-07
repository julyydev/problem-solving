// https://www.acmicpc.net/problem/9020
// written by julyy

#include <iostream>
#include <cmath>
using namespace std;

#define MAX 10000

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int prime[MAX + 1] = {0, };

    for (int i = 2; i <= MAX; i++) {
        prime[i] = i;
    }

    for (int i = 2; i <= sqrt(MAX); i++) {
        if (prime[i]) {
            for (int j = i * i; j <= MAX; j += i)
                prime[j] = 0;
        }
    }

    int T, n, a, b;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> n;

        for (int j = n / 2; j >= 2; j--) {
            if (prime[j] && prime[n - j]) {
                a = j, b = n - j;
                break;
            }
        }

        cout << a << " " << b << "\n"; 
    }

    return 0;
}
