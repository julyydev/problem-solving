#include <iostream>
using namespace std;

int main() {
    int n, result = 1;
    cin >> n;
    
    for (int i = 0; i < n; i++) result *= 2;
    cout << result << "\n";
    
    return 0;
}