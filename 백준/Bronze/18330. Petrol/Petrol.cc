#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    cout << min(n, k + 60) * 1500 + max(0, n - k - 60) * 3000 << "\n";
    
    
    return 0;
}