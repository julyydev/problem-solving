#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, b, sum = 0;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) cin >> prices[i];
    
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> b;
        sum += prices[b - 1];
    }
    cout << sum << "\n";
    
    return 0;
}