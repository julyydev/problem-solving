// https://www.acmicpc.net/problem/1546
// written by julyy

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, score, sum = 0, max = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> score;
        sum += score * 100;
        if (score > max) {
            max = score;
        }
    }
    float average = (float)sum / (max * n);

    cout << fixed;
    cout.precision(6);
    cout << average << '\n';

	return 0;
}
