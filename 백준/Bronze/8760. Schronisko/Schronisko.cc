#include <iostream>
using namespace std;

int main() {
    int t, w, k;
    cin >> t;
    
    while (t--) {
        cin >> w >> k;
        cout << w * k / 2 << "\n";
    }
    
    return 0;
}