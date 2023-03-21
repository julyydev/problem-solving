#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K, c, sum = 0;
    vector<int> coin;
    cin >> N >> K;

    while (N--) {
        cin >> c;
        if (c <= K) coin.push_back(c);
    }

    for (int i = coin.size() - 1; i >= 0; i--) {
        if (coin[i] > K) continue;
        sum += K / coin[i];
        K %= coin[i];
        if (K == 0) break;
    }

    cout << sum << "\n";

    return 0;
}