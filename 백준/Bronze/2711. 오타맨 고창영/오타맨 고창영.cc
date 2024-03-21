#include <iostream>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    
    string s;
    while (t--) {
        cin >> n >> s;
        for (int i = 1; i <= s.length(); i++) {
            if (i == n) continue;
            cout << s[i - 1];
        }
        cout << "\n";
    }
    
    return 0;
}