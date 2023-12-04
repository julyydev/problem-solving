#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    const int gx[6] = {1, 2, 3, 3, 4, 10};
    const int sx[7] = {1, 2, 2, 2, 3, 5, 10};
    
    for (int b = 1; b <= t; b++) {
        int g = 0, s = 0, x;
        
        for (int i = 0; i < 6; i++) {
            cin >> x;
            g += gx[i] * x;
        }
        
        for (int i = 0; i < 7; i++) {
            cin >> x;
            s += sx[i] * x;
        }
        
        cout << "Battle " << b << ": ";
        if (g > s) cout << "Good triumphs over Evil\n";
        else if (s > g) cout << "Evil eradicates all trace of Good\n";
        else cout << "No victor on this battle field\n"; 
    }
    
    return 0;
}