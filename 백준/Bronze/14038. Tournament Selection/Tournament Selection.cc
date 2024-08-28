#include <iostream>
using namespace std;

int main() {
    int count = 0;
    char c;
    
    for (int i = 0; i < 6; i++) {
        cin >> c;
        if (c == 'W') count++;
    }
    
    if (count >= 5) cout << "1\n";
    else if (count >= 3) cout << "2\n";
    else if (count >= 1) cout << "3\n";
    else cout << "-1\n";
    
    return 0;
}