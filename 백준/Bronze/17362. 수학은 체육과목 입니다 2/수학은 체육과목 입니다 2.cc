#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    switch (n % 8) {           
        case 1:
            cout << 1 << "\n";
            break;
        case 2:
            cout << 2 << "\n";
            break;
        case 3:
            cout << 3 << "\n";
            break;
        case 4:
            cout << 4 << "\n";
            break;
        case 5:
            cout << 5 << "\n";
            break;
        case 6:
            cout << 4 << "\n";
            break;
        case 7:
            cout << 3 << "\n";
            break;
        case 0:
            cout << 2 << "\n";
            break;
    }
    
    return 0;
}