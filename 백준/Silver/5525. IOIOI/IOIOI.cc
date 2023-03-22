#include <iostream>
using namespace std;

int main() {
    int N, M, count = 0;
    string s;
    cin >> N >> M >> s;

    for (int i = 0; i < M; i++) {
        if (s[i] == 'I') {
            int j = i + 1;
            while (1) {
                if (j > M) break;
                if (s[j] != 'O' || s[j + 1] != 'I') break;
                j += 2;
            }

            if (j - i >= 2 * N + 1) count += (j - i - 1) / 2 - N + 1;

            if (s[j] == 'O')
                i = j;
            else
                i = j - 1;
        }
    }

    cout << count << "\n";

    return 0;
}
