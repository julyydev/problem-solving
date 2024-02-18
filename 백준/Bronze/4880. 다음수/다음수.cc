#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    while (1) {
        cin >> a >> b >> c;
        if (!a && !b && !c) break;
        
        if (2 * b == a + c)
            cout << "AP " << 2 * c - b << "\n";
        else
            cout << "GP " << c * c / b << "\n";
    }
    
    return 0;
}