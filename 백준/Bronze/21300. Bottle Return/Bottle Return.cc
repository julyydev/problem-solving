#include <iostream>
using namespace std;

int main() {
    int sum = 0, x;
    for (int i = 0; i < 6; i++) {
        cin >> x;
        sum += x;
    }
    
    cout << sum * 5  << "\n";
    
    return 0;
}