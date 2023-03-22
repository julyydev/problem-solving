#include <iostream>
using namespace std;

int main() {
    int N, M, count = 0;
    string s;
    cin >> N >> M >> s;

    for (int i = 0; i < M; i++) {
        if (s[i] == 'I') {
            bool isSatisfied = true;
            for (int j = i + 1; j <= i + 2 * N; j += 2) {
                if (j > M) break;
                if (s[j] != 'O' || s[j + 1] != 'I') {
                    isSatisfied = false;
                    break;
                }
            }
            if (isSatisfied) count++;
        }
    }

    cout << count << "\n";

    return 0;
}