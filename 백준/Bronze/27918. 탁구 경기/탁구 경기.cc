#include <iostream>
using namespace std;

int main() {
    int n, d = 0, p = 0;
    char x;
    cin >> n;
    
    while (n--) {
        cin >> x;
        if (x == 'D') d++;
        else p++;
        
        if (d - p > 1 || p - d > 1) break;
    }
    cout << d << ":" << p << "\n";
    
    return 0;
}