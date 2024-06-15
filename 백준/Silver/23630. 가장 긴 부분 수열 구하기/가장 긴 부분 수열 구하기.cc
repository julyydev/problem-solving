#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int n, x;
    cin >> n;

    vector<int> counts(21, 0);  // log(2)100 ~= 20
    for (int i = 0; i < n; i++) {
        cin >> x;
        int e = 0;

        while (x) {
            if (x % 2 == 1) counts[e]++;
            x /= 2;
            e++;
        }
    }

    int max_count = 0;
    for (int count : counts) max_count = max(max_count, count);
    cout << max_count << "\n";

    return 0;
}