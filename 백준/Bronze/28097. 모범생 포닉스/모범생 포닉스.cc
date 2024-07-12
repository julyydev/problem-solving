#include <iostream>
using namespace std;

int main() {
    int n, temp, res = 0;
    cin >> n;
    res += (n - 1) * 8;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        res += temp;
    }
    cout << res / 24 << " " << res % 24;
    
    return 0;
}