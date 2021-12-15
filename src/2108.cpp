// https://www.acmicpc.net/problem/2108
// written by julyy

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, n, sum = 0, mid_count = 0, mode_count = 0, max = -4000, min = 4000;
    vector<int> mode(0);
    int count[8001] = {0, };
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> n;
        sum += n;

        count[n + 4000]++;
        if (count[n + 4000] > mode_count) {
            mode_count = count[n + 4000];
            mode.clear();
            mode.push_back(n);
        }
        else if (count[n + 4000] == mode_count) {
            mode.push_back(n);
        }

        if (n > max)
            max = n;
        if (n < min)
            min = n;
    }
    cout << (int)floor((double)sum / N + 0.5) << '\n'; // 산술평균
    for (int i = 0; i < 8001; i++) { // 중앙값
        mid_count += count[i];
        if (mid_count >= N / 2 + 1) {
            cout << i - 4000 << '\n';
            break;
        }
    }
    if (mode.size() == 1) // 최빈값
        cout << mode[0] << '\n';
    else {
        sort(mode.begin(), mode.end());
        cout << mode[1] << '\n';
    }
    cout << max - min << '\n'; // 범위

    return 0;
}
