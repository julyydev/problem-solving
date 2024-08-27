#include <iostream>
using namespace std;

int main() {
    int n, odd = 0, even = 0;
    string k;
    cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        if ((k[i] - '0') % 2 == 0) even++;
        else odd++;
    }
    
    if (odd > even) cout << "1\n";
    else if (even > odd) cout << "0\n";
    else cout << "-1\n";
    
    return 0;
}