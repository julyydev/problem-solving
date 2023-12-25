#include <iostream>
using namespace std;

int main() {
    int n, x, y;
    cin >> n;
    
    while (n--) {
        cin >> x >> y;
        if (x < y) cout << "NO BRAINS\n";
        else cout << "MMM BRAINS\n";
    }
    
    return 0;
}