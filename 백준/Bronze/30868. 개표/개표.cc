#include <iostream>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    
    while (t--) {
        cin >> n;
        for (int k = 0; k < n / 5; k++) cout << "++++ ";
        for (int k = 0; k < n % 5; k++) cout << "|";
        cout << "\n";
    }
    
    return 0;
}