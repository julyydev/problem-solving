#include <algorithm>
#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int n;
    cin >> n;
    if (n == 0) {
        cout << "0\n";
        return 0;
    }

    vector<int> difficulty(n);
    for (int i = 0; i < n; i++) cin >> difficulty[i];
    sort(difficulty.begin(), difficulty.end());

    int ex = (n * 15 % 100 >= 50 ? n * 15 / 100 + 1 : n * 15 / 100);
    int sum = 0;
    for (int i = ex; i < n - ex; i++) sum += difficulty[i];
    if (2 * (sum % (n - 2 * ex)) >= (n - 2 * ex))
        cout << sum / (n - 2 * ex) + 1 << "\n";
    else
        cout << sum / (n - 2 * ex) << "\n";

    return 0;
}
