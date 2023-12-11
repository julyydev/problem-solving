#include <iostream>
using namespace std;

int main() {
    int t, s, n, p, q;
    cin >> t;
    
    while (t--) {
        int sum = 0;
        cin >> s >> n;
        sum += s;
        
        for (int i = 0; i < n; i++) {
            cin >> q >> p;
            sum += q * p;
        }
        
        cout << sum << "\n";
    }
    return 0;
}