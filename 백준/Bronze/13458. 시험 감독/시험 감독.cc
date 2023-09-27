#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int n, b, c;
    long long result = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> b >> c;

    result += n;
    for (int i = 0; i < n; i++) {
        if (a[i] <= b) continue;
        result += (a[i] - b) / c;
        if ((a[i] - b) % c > 0) result++;
    }

    cout << result << "\n";

    return 0;
}