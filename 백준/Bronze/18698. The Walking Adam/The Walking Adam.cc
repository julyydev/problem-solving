#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    string s;
    while (t--) {
        int n = 0;
        cin >> s;
        for (auto c : s) {
            if (c == 'D') break;
            n++;
        }
        cout << n << '\n';
    }
    
    return 0;
}