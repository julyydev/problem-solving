#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M, i, j, k;
    cin >> N >> M;
    vector<int> vec(N + 1, 0);

    while (M--) {
        cin >> i >> j >> k;
        for (; i <= j; i++) vec[i] = k;
    }

    for (int i = 1; i <= N; i++) cout << vec[i] << " ";
    cout << "\n";

    return 0;
}
