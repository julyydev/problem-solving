#include <iostream>
using namespace std;

int main() {
    int n, sum = 0, cubic_sum = 0;
    cin >> n;
    
    for (int i = 1; i <= n; i++) sum += i;
    cout << sum << "\n";
    cout << sum * sum << "\n";
    
    for (int i = 1; i <= n; i++) cubic_sum += i * i * i;
    cout << cubic_sum << "\n";
    
    return 0;
}