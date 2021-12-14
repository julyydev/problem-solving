// https://www.acmicpc.net/problem/3052
// written by julyy

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int count[42] = {0,};
    int n, sum = 0;

    for (int i = 0; i < 10; i++) {
        cin >> n;
        count[n % 42] = 1;
    }

    for (int i = 0; i < 42; i++) {
        sum += count[i];
    }
    cout << sum << '\n';

	return 0;
}
