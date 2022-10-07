// https://www.acmicpc.net/problem/6588
// written by julyy

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
#define MAX 1000000

int prime[MAX] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 2; i <= MAX; i++) {
        prime[i] = i;
    }

    for (int i = 2; i <= sqrt(MAX); i++) {
        if (prime[i]) {
            for (int j = i * i; j < MAX; j += i) {
                prime[j] = 0;
            }
        }
    }

    int n = 1;
    while (1) {
        cin >> n;
        if (n == 0)
            break;
        
        int i;
        for (i = 3; i <= n / 2; i += 2) {
            if (prime[i]) {
                if (prime[n - i]) {
                    cout << n << " = " << i << " + " << n - i << '\n';
                    break;
                }
            }
        }
        if (i == n / 2 + 1)
            cout << "Goldbach's conjecture is wrong.\n";
    }
    
    return 0;
}
