#include <iostream>
using namespace std;
 
int main() {
    int k, d, a;
    char c;
    cin >> k >> c >> d >> c >> a;
    
    if (k + a < d || d == 0) cout << "hasu\n";
    else cout << "gosu\n";
    
    return 0;
}