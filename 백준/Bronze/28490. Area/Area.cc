#include <iostream>
using namespace std;

int main() {
    int n, w, h, large = 0;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> w >> h;
        large = max(large, w * h);
    }
    
    cout << large << "\n";
    
    return 0;
}