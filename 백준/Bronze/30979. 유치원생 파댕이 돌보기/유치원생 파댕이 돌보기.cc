#include <iostream>
using namespace std;

int main() {
    int t, n, f, sum = 0;
    cin >> t >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> f;
        sum += f;
    }
    
    if (sum >= t) cout << "Padaeng_i Happy\n";
    else cout << "Padaeng_i Cry\n";
    
    return 0;
}