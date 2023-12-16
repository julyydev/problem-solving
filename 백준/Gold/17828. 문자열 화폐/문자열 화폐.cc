#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int n, x;
    cin >> n >> x;

    if (n * 26 < x || n > x) {
        cout << "!\n";
        return 0;
    }

    string ans(n, 'A');
    x -= n;
    int d = x / 25, r = x % 25, i;
    for (i = 0; i < d; i++) ans[n - 1 - i] += 25;
    ans[n - 1 - i] += r;

    cout << ans << "\n";

    return 0;
}