#include <iostream>
using namespace std;

int main() {
    int a, p;
    cin >> a >> p;
    a *= 7, p *= 13;
    
    if (a > p) cout << "Axel\n";
    else if (p > a) cout << "Petra\n";
    else cout << "lika\n";
    
    return 0;
}