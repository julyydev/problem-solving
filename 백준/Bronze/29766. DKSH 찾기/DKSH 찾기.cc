#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int count = 0;
    for (int i = 0; i < s.length() - 3; i++) {
        if (s[i] == 'D' && s[i + 1] == 'K' && s[i + 2] == 'S' && s[i + 3] == 'H') {
            count++;
            i += 3;
        }
    }
    cout << count << "\n";
    
    return 0;
}