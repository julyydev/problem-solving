#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<int> prices(n);
    for (int i = 0; i < n; i++) cin >> prices[i];
    
    int min_sum = 100000000;
    for (int i = 0; i < n - 1; i++)
        min_sum = min(min_sum, prices[i] + prices[i + 1]);
    cout << min_sum * x << '\n';
    
    return 0;
}