#include <iostream>
using namespace std;

int main() {
    int n, x, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        sum += x;
    }
    
    if (sum > 0) cout << "Right\n";
    else if (sum < 0) cout << "Left\n";
    else cout << "Stay\n";
    
    return 0;
}