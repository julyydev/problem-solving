#include <iostream>
using namespace std;

int main() {
    int a3, a2, a1, b3, b2, b1, a, b;
    cin >> a3 >> a2 >> a1 >> b3 >> b2 >> b1;
    
    a = 3 * a3 + 2 * a2 + a1;
    b = 3 * b3 + 2 * b2 + b1;
    
    if (a > b) cout << "A\n";
    else if (b > a) cout << "B\n";
    else cout << "T\n";
    
    return 0;
}