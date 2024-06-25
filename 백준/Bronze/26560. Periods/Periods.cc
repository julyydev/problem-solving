#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    
    string s;
    while (n--) {
        getline(cin, s);
        if (s.back() != '.') s += '.';
        cout << s << "\n";
    }
    
    return 0;
}