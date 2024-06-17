#include <iostream>
using namespace std;

int main() {
    int m, p, l, e, r, s, n;
    while (cin >> m >> p >> l >> e >> r >> s >> n) {
        while (n--) {
            int nm = p / s, np = l / r, nl = m * e;
            m = nm, p = np, l = nl;
        }
        cout << m << "\n";
    }
    return 0;
}