#include <iostream>
using namespace std;

int main() {
    int value = 0, t, e, f;
    cin >> t >> e >> f;
    value = value + t * 3 + e * 20 + f * 120;
    cin >> t >> e >> f;
    value = value - t * 3 - e * 20 - f * 120;
    
    if (value > 0) cout << "Max\n";
    else if (value < 0) cout << "Mel\n";
    else cout << "Draw\n";
    
    return 0;
}