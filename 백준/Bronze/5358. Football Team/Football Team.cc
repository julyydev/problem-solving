#include <iostream>
using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        for (auto c : s) {
            if (c == 'e') cout << 'i';
            else if (c == 'i') cout << 'e';
            else if (c == 'E') cout << 'I';
            else if (c == 'I') cout << 'E';
            else cout << c;
        }
        cout << "\n";
    }
    
    return 0;
}