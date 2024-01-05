#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int i = 0;
    while (i < s.length()) {
       cout << s[i];
       i += s[i] - 'A' + 1;
    }
    cout << "\n";
    
    return 0;
}