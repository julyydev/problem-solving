#include <iostream>
using namespace std;

int main() {
    int t, g, c, e;
    cin >> t;
    
    while (t--) {
        cin >> g >> c >> e;
        if (c >= e) {
            cout << 0 << "\n";
            continue;
        }
        cout << (e - c) * (2 * g - 1) << "\n";
    }
    
    return 0;
}