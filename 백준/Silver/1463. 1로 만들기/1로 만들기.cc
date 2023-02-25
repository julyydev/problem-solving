#include <iostream>
using namespace std;

int cnt[1000001] = {
    0,
};

int main() {
    cnt[1] = 0;
    cnt[2] = 1;
    cnt[3] = 1;

    int N, min;
    cin >> N;

    for (int i = 4; i <= N; i++) {
        min = 1000002;
        if (i % 3 == 0) {
            min = min > cnt[i / 3] + 1 ? cnt[i / 3] + 1 : min;
        }
        if (i % 2 == 0) {
            min = min > cnt[i / 2] + 1 ? cnt[i / 2] + 1 : min;
        }
        min = min > cnt[i - 1] + 1 ? cnt[i - 1] + 1 : min;
        cnt[i] = min;
    }

    cout << cnt[N] << '\n';

    return 0;
}