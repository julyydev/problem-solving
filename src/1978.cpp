// https://www.acmicpc.net/problem/1978
// written by julyy

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, num, count = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        bool isPrime = true;
        cin >> num;

        if (num == 1)
            continue;
        if (num == 2) {
            count++;
            continue;
        }
        for (int j = 2; j <= sqrt(num); j++) {
            if (num % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
            count++;
    }
    cout << count;

    return 0;
}
