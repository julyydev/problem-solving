#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int n, x;
    cin >> n;

    while (1) {
        cin >> x;
        if (x == 0) break;
        cout << x << " is " << ((x % n == 0) ? "" : "NOT ") << "a multiple of "
             << n << ".\n";
    }

    return 0;
}