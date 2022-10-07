// https://www.acmicpc.net/problem/2562
// written by julyy

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, max = 0, maxIndex = 0;

    for (int i = 1; i <= 9; i++) {
        cin >> n;
        if (n > max) {
            max = n, maxIndex = i;
        }
    }
    cout << max << "\n" << maxIndex << "\n";

	return 0;
}
