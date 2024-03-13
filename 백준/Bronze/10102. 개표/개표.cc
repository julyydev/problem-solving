#include <iostream>
using namespace std;

int main() {
    int n, a = 0, b = 0;
    string s;
    cin >> n >> s;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') a++;
        else b++;
    }
    
    if (a > b) cout << "A\n";
    else if (a < b) cout << "B\n";
    else cout << "Tie\n";
    
    return 0;
}