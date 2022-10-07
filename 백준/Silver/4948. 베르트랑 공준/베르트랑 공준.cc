// https://www.acmicpc.net/problem/4948
// written by julyy

#include <iostream>
#include <cmath>
using namespace std;

#define MAX 123456 * 2

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

    int n, count;
    while(1) {
        cin >> n;
        if (n == 0)
            break;

        count = 0;
        for (int i = n + 1; i <= 2 * n; i++) {
            if (prime[i])
                count++;
        }
        cout << count << '\n';
    }

    return 0;
}
