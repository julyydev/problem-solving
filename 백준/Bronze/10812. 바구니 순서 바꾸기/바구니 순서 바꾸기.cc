#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M, i, j, k;
    cin >> N >> M;
    vector<int> vec(N + 1);
    for (int i = 1; i <= N; i++) vec[i] = i;

    while (M--) {
        cin >> i >> j >> k;
        rotate(vec.begin() + i, vec.begin() + k, vec.begin() + j + 1);
    }

    for (int i = 1; i <= N; i++) cout << vec[i] << " ";
    cout << "\n";

    return 0;
}