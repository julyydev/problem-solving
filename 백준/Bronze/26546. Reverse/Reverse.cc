#include <iostream>
using namespace std;

int main() {
    int n, x, y;
    cin >> n;
    
    string s;
    while (n--) {
        cin >> s >> x >> y;
        for (int i = 0; i < s.length(); i++) {
            if (i >= x && i < y) continue;
            cout << s[i];
        }
        cout << "\n";
    }
    
    return 0;
}