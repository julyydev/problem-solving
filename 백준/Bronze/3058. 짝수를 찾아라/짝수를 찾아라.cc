#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int sum = 0, min_n = 100000000, n;
        for (int i = 0; i < 7; i++) {
            cin >> n;
            if (n % 2 == 0) {
                sum += n;
                min_n = min(min_n, n);
            }
        }
        
        cout << sum << " " << min_n << "\n";
    }
    
    return 0;
}