// https://www.acmicpc.net/problem/10952
// written by julyy

#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;

    while (a || b) {
        cout << a + b << "\n";
        cin >> a >> b;
    }

	return 0;
}
