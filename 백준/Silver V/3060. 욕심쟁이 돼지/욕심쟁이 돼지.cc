#include <iostream>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    
    while (t--) {
        cin >> n;
        
        long long sum = 0, x;
        for (int i = 0; i < 6; i++) {
            cin >> x;
            sum += x;
        }
        
        int day = 1;
        while (sum <= n) {
            sum *= 4;
            day++;
        }
        
        cout << day << "\n";
    }
    
    return 0;
}