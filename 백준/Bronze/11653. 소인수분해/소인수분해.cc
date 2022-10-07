// https://www.acmicpc.net/problem/11653
// written by julyy

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, i = 2;
    cin >> N;

    while (N > 1) {
        if (N % i == 0) {
            cout << i << '\n';
            N /= i;
        }
        else
            i++;
    }

    return 0;
}
