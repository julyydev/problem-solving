// https://www.acmicpc.net/problem/10871
// written by julyy

#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, x, a;
    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a < x) {
            cout << a << ' ';
        }
    }

	return 0;
}
