#include <cmath>
#include <iostream>
using namespace std;

int main() {
    long long k, n;
    cin >> k >> n;
    if (n == 1) {
        cout << -1 << '\n';
        return 0;
    }
    cout << n * k / (n - 1) + (n * k % (n - 1) != 0 ? 1 : 0) << "\n";
    
    return 0;
}