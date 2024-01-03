#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    if (s.length() == 4) {
        cout << 20 << "\n";
        return 0;
    }
    
    if (s.length() == 2) {
        cout << s[0] - '0' + s[1] - '0' << "\n";
        return 0;
    }
    
    if (s[1] == '0')
        cout << 10 + s[2] - '0' << "\n";
    else
        cout << s[0] - '0' + 10 << "\n";

    return 0;
}