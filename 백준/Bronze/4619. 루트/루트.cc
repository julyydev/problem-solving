#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int b, n;
    while (1) {
        cin >> b >> n;
        if (b == 0 && n == 0) break;
        
        int a, min_diff = 100000000;
        for (int temp_a = 1; pow(temp_a, n) <= 2000000; temp_a++) {
            int diff = abs(pow(temp_a, n) - b);
            if (diff < min_diff) {
                min_diff = diff;
                a = temp_a;
            }
        }
        
        cout << a << "\n";
    }
    
    return 0;
}