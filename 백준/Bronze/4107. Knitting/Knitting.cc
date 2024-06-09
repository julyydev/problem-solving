#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int n, m, k;
    while (1) {
        cin >> n >> m >> k;
        if (n == 0 && m == 0 && k == 0) break;

        vector<int> pattern(k);
        for (int i = 0; i < k; i++) cin >> pattern[i];

        int sum = 0, cur = n, p = 0;
        for (int i = 0; i < m; i++) {
            sum += cur;
            cur += pattern[p++];
            if (p == k) p = 0;
        }
        cout << sum << "\n";
    }

    return 0;
}