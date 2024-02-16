#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    long long x;
    while (n--) {
        cin >> x;
        cout << (((long long)sqrt(x) * (long long)sqrt(x) == x) ? 1 : 0) << " ";
    }
    cout << "\n";
    
    return 0;
}