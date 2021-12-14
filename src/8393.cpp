// https://www.acmicpc.net/problem/8393
// written by julyy

#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    cout << sum << endl;

	return 0;
}
