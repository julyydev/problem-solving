#include <iostream>
using namespace std;

int main() {
    int n, a_sum = 100, b_sum = 100, a, b;
    cin >> n;
    
    while (n--) {
        cin >> a >> b;
        if (a < b) a_sum -= b;
        else if (b < a) b_sum -= a;
    }
    cout << a_sum << "\n" << b_sum << "\n"; 
    
    return 0;
}