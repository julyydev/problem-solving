#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    
    int m = max(a, max(b, c));
    cout << (m - a) + (m - b) + (m - c) << "\n";
    
    return 0;
}