#include <iostream>
using namespace std;

int main() {
    int x, n;
    cin >> x >> n;
    
    while (n--) {
        if (x % 2 == 0) x /= 2;
        else x *= 2;
        x ^= 6;
    }
    cout << x << "\n";
    
    return 0;
}