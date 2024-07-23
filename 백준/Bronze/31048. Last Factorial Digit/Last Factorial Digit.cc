#include <iostream>
using namespace std;

int factorial_digit(int n) {
    if (n == 1) return 1;
    return n * factorial_digit(n - 1) % 10;
}

int main() {
    int t, n;
    cin >> t;
    
    while (t--) {
        cin >> n;
        cout << factorial_digit(n) << "\n";
    }
    
    return 0;
}