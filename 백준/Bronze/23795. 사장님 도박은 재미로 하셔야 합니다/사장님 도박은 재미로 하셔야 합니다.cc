#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int sum = 0, x;

    while (1) {
        cin >> x;
        if (x == -1) break;
        sum += x;
    }
    cout << sum << "\n";

    return 0;
}