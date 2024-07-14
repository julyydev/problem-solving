#include <iostream>
using namespace std;

int main() {
    int a, b, k, x;
    cin >> a >> b >> k >> x;
    
    int low = max(k - x, a);
    int high = min(k + x, b);
    
    if (high < low) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    
    cout << high - low + 1 << "\n";
    return 0;
}