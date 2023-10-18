#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    
    if (a >= 20)
        cout << 24 + b - a << "\n";
    else
        cout << b - a << "\n";
    
    return 0;
}