#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    cout << fixed;
    cout.precision(2);
    cout << (double)n / 4 << "\n";
    
    return 0;
}