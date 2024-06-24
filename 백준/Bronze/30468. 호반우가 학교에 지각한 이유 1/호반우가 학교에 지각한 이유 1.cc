#include <iostream>
using namespace std;

int main() {
    int s, d, i, l, n;
    cin >> s >> d >> i >> l >> n;
    cout << max(4 * n - (s + d + i + l ), 0) << "\n";
    
    return 0;
}