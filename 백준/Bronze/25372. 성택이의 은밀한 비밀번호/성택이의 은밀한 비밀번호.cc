#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    string s;
    while (n--) {
        cin >> s;
        if (s.length() >= 6 && s.length() <= 9) cout << "yes\n";
        else cout << "no\n";
    }
    
    return 0;
}