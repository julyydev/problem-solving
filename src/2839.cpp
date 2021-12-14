// https://www.acmicpc.net/problem/2839
// written by julyy

#include <iostream>
using namespace std;

int main() {
    int N, three = 0, five;
    cin >> N;

    five = N / 5;
    for (five; five >= 0; five--) {
        if ((N - 5 * five) % 3 == 0) {
            three = (N - 5 * five) / 3;
            break;
        }
    }
    if (five == -1)
        five = 0;

    if (!three && !five)
        cout << -1;
    else
        cout << three + five;

    return 0;
}
