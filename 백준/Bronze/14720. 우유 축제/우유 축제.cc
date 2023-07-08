#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int n, x, count = 0, cur = 0;
    cin >> n;

    while (n--) {
        cin >> x;
        if (cur == x) {
            count++;
            cur = (cur + 1) % 3;
        }
    }
    cout << count << "\n";

    return 0;
}