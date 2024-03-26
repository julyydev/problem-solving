#include <iostream>
using namespace std;

int main() {
    int aa, ad, ba, bd;
    cin >> aa >> ad >> ba >> bd;
    
    while (ad > 0 && bd > 0) {
        ad -= ba;
        bd -= aa;   
    }
    
    if (ad > 0 && bd <= 0)
        cout << "PLAYER A\n";
    else if (bd > 0 && ad <= 0)
        cout << "PLAYER B\n";
    else
        cout << "DRAW\n";
    
    return 0;
}