#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    while (n > 1) {
        if (n % 2 == 1) {
            cout << 0 << "\n";
            return 0;
        }
        
        n /= 2;
    }
    cout << 1 << "\n";
    
    return 0;
}