#include <iostream>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    
    while (t--) {
        cin >> n;
        int i = 0;
        while (n) {
            if (n % 2 == 1) cout << i << " ";
            n /= 2;
            i++;
        }
        cout << "\n";
    }
    
    return 0;
}