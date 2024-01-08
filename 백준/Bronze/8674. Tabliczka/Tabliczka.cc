#include <iostream>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    
    if (a * b % 2 == 0) cout << "0\n";
    else cout << min(a, b) << "\n";
 
    return 0;
}