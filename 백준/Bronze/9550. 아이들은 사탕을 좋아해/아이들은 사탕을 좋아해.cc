#include <iostream>
using namespace std;

int main() {
    int t, n, k, x;
    cin >> t;
    
    while (t--) {
        cin >> n >> k;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> x;
            sum += x / k;
        }
        cout << sum << "\n";
    }
    
    return 0;
}