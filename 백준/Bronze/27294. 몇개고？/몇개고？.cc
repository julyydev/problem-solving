#include <iostream>
using namespace std;

int main() {
    int t, s;
    cin >> t >> s;
    
    if (t >= 12 && t <= 16 && s == 0)
        cout << 320 << "\n";
    else
        cout << 280 << "\n";
    
    return 0;
}