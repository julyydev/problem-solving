// https://www.acmicpc.net/problem/2581
// written by julyy

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N, min = 0, sum = 0;
    bool isPrime;
    cin >> M >> N;

    for (int i = M; i <= N; i++) {
        isPrime = true;
        if (i == 1) {
            isPrime = false;
        }
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            if (!min)
                min = i;
            sum += i;
        }
    }
    
    if (!sum)
        cout << -1;
    else
        cout << sum << '\n' << min << '\n';

    return 0;
}
