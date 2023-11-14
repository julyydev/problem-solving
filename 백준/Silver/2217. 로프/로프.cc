#include <algorithm>
#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int n;
    cin >> n;

    vector<int> weights(n);
    for (int i = 0; i < n; i++) cin >> weights[i];
    sort(weights.begin(), weights.end(), greater<int>());

    int max_weight = 0;
    for (int i = 0; i < n; i++)
        max_weight = max(max_weight, weights[i] * (i + 1));

    cout << max_weight << "\n";

    return 0;
}