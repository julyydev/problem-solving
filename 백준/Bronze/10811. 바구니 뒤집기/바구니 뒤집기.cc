#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M, i, j;
    cin >> N >> M;
    vector<int> vec(N + 1);
    for (int i = 1; i <= N; i++) vec[i] = i;

    while (M--) {
        cin >> i >> j;
        for (int k = i; k <= (i + j) / 2; k++) {
            int temp = vec[k];
            vec[k] = vec[i + j - k];
            vec[i + j - k] = temp;
        }
    }

    for (int i = 1; i <= N; i++) cout << vec[i] << " ";
    cout << "\n";

    return 0;
}
