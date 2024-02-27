#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int l, r, a;
    cin >> l >> r >> a;
    cout << 2 * (min(l, r) + (abs(l - r) > a ? a : abs(l - r) + (max(a - (abs(l - r)), 0)) / 2)) << "\n";
    
    return 0;
}