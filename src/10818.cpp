// https://www.acmicpc.net/problem/10818
// written by julyy

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, a, min, max;
    cin >> n;

    cin >> a;
    min = a, max = a;
    for (int i = 1; i < n; i++) {
        cin >> a;
        if (min > a) {
            min = a;
        }
        if (max < a) {
            max = a;
        }
    }
    cout << min << " " << max << "\n";

	return 0;
}
