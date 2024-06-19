#include <iostream>
#include <cmath>
using namespace std;

int main() {
    string s;
    int r, b, t;
    cin >> s;
    
    for (int i = 0; i < 10; i++) {
        if (s[i] == '@') r = i;
        else if (s[i] == '#') b = i;
        else if (s[i] == '!') t = i;
    }
    
    if ((b < r && b < t) || (b > r && b > t)) {
        cout << -1 << "\n";
        return 0;
    }
    
    cout << abs(t - r) - 1 << "\n";
    return 0;
}