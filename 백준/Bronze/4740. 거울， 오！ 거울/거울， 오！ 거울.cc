#include <iostream>
using namespace std;

int main() {
    string s;
    while (1) {
        getline(cin, s);
        if (s == "***") break;
        
        for (int i = s.length() - 1; i >= 0; i--)
            cout << s[i];
        cout << "\n";
    }
    return 0;
}