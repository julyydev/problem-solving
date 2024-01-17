#include <iostream>
using namespace std;

int main() {
    int n, d, l, r;
    cin >> n;
    
    while (n--) {
        cout << "Denominations: ";
        bool good = true;
        cin >> d;
        for (int i = 0; i < d; i++) {
            l = r;
            cin >> r;
            cout << r << " ";
            if (i == 0) continue;
            
            if (r < 2 * l) good = false;
        }
        cout << "\n" << (good ? "Good" : "Bad") << " coin denominations!\n\n";
    }
    
    return 0;
}