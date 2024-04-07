#include <iostream>
using namespace std;

int main() {
    int m, k;
    cin >> m >> k;
    
    if (m % k == 0) cout << "Yes\n";
    else cout << "No\n";
    
    return 0;
}