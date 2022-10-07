// https://www.acmicpc.net/problem/10250
// written by julyy

#include <iostream>
using namespace std;

int main() {
    int T, H, W, N;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> H >> W >> N;
        if (N % H == 0)
            cout << H;
        else
            cout << N % H;
        if ((N - 1) / H < 9)
            cout << 0;
        cout << (N - 1) / H + 1 << '\n';
    }

    return 0;
}
