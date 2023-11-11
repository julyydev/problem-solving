#include <iostream>
using namespace std;

int main() {
    int odd = 0, even = 0, n, x;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x % 2 == 0) even++;
        else odd++;
    }
    
    if (even > odd) cout << "Happy\n";
    else cout << "Sad\n";
    
    return 0;
}