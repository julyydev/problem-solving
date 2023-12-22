#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    string s;
    while (n--) {
        cin >> s;
        for (char& c : s) cout << (char)tolower(c);
        cout << "\n";
    }
    
    return 0;
}