#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    string s;
    while (n--) {
        cin >> s;
        char temp = ' ';
        for (auto c : s) {
            if (c == temp) continue;
            cout << c;
            temp = c;
        }
        cout << "\n";
    }
    
    return 0;
}