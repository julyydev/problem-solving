#include <iostream>
using namespace std;

int main() {
    int t, n;
    char c;
    cin >> t;
    
    while (t--) {
        cin >> n >> c;
        while (n--) cout << c;
        cout << "\n";
    }
    
    return 0;
}