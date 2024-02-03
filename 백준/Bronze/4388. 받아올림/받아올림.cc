#include <iostream>
using namespace std;

int main() {
    int a, b;
    
    while (1) {
        cin >> a >> b;
        if (a == 0 && b == 0) break;
        
        int carry_count = 0, carry = 0;
        while (a || b) {
            if (a % 10 + b % 10 + carry >= 10) {
                carry = 1;
                carry_count++;
            }
            else {
                carry = 0;
            }
                
            a /= 10, b /= 10;
        }
        cout << carry_count << "\n"; 
    }
    
    return 0;
}