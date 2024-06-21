#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    
    if (b > a) {
        cout << -1 << "\n";
        return 0;
    }
    
    int x = (a + b) / 2, y = (a - b) / 2;
    if (x + y != a || x - y != b) {
        cout << -1 << "\n";
        return 0;
    }

    cout << x << " " << y << "\n";
    return 0;
}