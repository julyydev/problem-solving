#include <iostream>
using namespace std;

int main() {
    int n, a, b, x;
    cin >> n;
    
    while (n--) {
        cin >> a >> b >> x;
        cout << a * (x - 1) + b << "\n";
    }
    
    return 0;
}