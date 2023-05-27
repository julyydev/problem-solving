#include <iostream>
using namespace std;

int main() {
    int n;
    bool check = true;
    
    for (int i = 0; i < 8; i++) {
        cin >> n;
        if (n != 0 && n != 1) check = false;
    }
    cout << (check ? "S" : "F") << "\n";
    
    return 0;
}