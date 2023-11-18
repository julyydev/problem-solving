#include <iostream>
using namespace std;

int main() {
    cin.ignore();
    
    while (1) {
        string s;
        getline(cin, s);
        if (s == "#") break;
        
        int n = 0;
        for (char c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
                n++;
        }
        
        cout << n << "\n";
    }
    
    return 0;
}