// https://www.acmicpc.net/problem/15552
// written by julyy

#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

	int t, a, b;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> a >> b;
        cout << a + b << "\n";
    }
    
	return 0;
}
