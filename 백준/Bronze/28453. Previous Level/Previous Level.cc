#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> m;
        if (m == 300) cout << "1 ";
        else if (m >= 275) cout << "2 ";
        else if (m >= 250) cout << "3 ";
        else cout << "4 ";
    }
    
    return 0;
}