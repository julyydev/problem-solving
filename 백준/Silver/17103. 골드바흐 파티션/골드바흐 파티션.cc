// https://www.acmicpc.net/problem/17103
// written by julyy

#include <iostream>
#include <cmath>
using namespace std;
#define MAX 1000000

int prime[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < MAX; i++) {
        prime[i] = i;
    }
    prime[1] = 0;

    for (int i = 2; i < sqrt(MAX); i++) {
        if (prime[i]) {
            for (int j = i * i; j < MAX; j += i)
                prime[j] = 0;
        }
    }

    int T, N, partition;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N;
        partition = 0;

        for (int j = 2; j <= N / 2; j++) {
            if (prime[j] && prime[N - j])
                partition++;
        }
        cout << partition << '\n';
    }
    
    return 0;
}
