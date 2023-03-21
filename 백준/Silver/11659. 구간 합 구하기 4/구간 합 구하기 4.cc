#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int N, M, v, i, j;
    cin >> N >> M;

    vector<int> prefixSum;

    cin >> v;
    prefixSum.push_back(0);
    prefixSum.push_back(v);
    for (int i = 2; i < N + 1; i++) {
        cin >> v;
        prefixSum.push_back(prefixSum[i - 1] + v);
    }

    while (M--) {
        cin >> i >> j;
        cout << prefixSum[j] - prefixSum[i - 1] << "\n";
    }

    return 0;
}