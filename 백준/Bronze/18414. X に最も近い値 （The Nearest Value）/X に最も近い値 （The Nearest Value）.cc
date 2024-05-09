#include <iostream>
using namespace std;

int main() {
    int x, l, r;
    cin >> x >> l >> r;
    
    if (x >= l && x <= r) cout << x << '\n';
    else if (x <= l) cout << l << '\n';
    else cout << r << '\n';
    
    return 0;
}