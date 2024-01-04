#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, p, ans;
    cin >> n >> p;
    ans = p;
    
    if (n >= 5)
        ans = min(ans, p - 500);
    
    if (n >= 10)
        ans = min(ans, p * 90 / 100);
    
    if (n >= 15)
        ans = min(ans, p - 2000);
    
    if (n >= 20)
        ans = min(ans, p * 75 / 100);
   
    if (ans < 0) ans = 0;
    
    cout << ans << "\n";
    
    return 0;
}