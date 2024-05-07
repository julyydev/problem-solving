#include <iostream>
using namespace std;

int main() {
    long long n, p, t;
    cin >> n;
    
    while (n--) {
        cin >> p >> t;
        cout << p + t / 4 - t / 7 << "\n";
    }
    
    return 0;
}