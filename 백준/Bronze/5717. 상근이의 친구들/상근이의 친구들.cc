#include <iostream>
using namespace std;

int main() {
    int m, f;
    
    while (1) {
        cin >> m >> f;
        if (!m && !f) break;
        
        cout << m + f << "\n";
    }
    
    return 0;
}