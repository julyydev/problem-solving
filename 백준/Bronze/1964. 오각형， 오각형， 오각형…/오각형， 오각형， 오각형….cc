#include <iostream>
using namespace std;

int penta(int n) {
    if (n == 0) return 1;
    return (3 * n + 1 + penta(n - 1)) % 45678;
}

int main() {
    int n;
    cin >> n;
    cout << penta(n) << "\n";
    
    return 0;
}