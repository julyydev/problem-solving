#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b, n, x;
    cin >> a >> b >> n;
    
    int result = abs(b - a);
    while (n--) {
        cin >> x;
        result = min(result, abs(b - x) + 1);
    }   
    
    cout << result << "\n";
    
    return 0;
}