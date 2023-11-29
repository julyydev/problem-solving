#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, p1 = 0, p2 = 0;
        char a, b;
        cin >> n;
        
        while (n--) {
            cin >> a >> b;
            if (a == 'R') {
                if (b == 'P') p2++;
                else if (b == 'S') p1++;
            } else if (a == 'P') {
                if (b == 'S') p2++;
                else if (b == 'R') p1++;
            } else {
                if (b == 'R') p2++;
                else if (b == 'P') p1++;
            }
        }
        
        if (p1 > p2) cout << "Player 1\n";
        else if (p1 < p2) cout << "Player 2\n";
        else cout << "TIE\n";
    }
    
    return 0;
}