#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    
    if (a == b && b == c) cout << "2\n";
    else if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) cout << "1\n";
    else cout << "0\n";
    
    return 0;
}