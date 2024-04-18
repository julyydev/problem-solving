#include <iostream>
using namespace std;

int main() {
    int sum = 0, x;
    for (int i = 0; i < 3; i++) {
        cin >> x;
        sum += x;
    }
    
    cout << (sum < 5 ? 1 : 2) << "\n";
    
    return 0;
}