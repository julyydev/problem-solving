#include <iostream>
using namespace std;

int main() {
    int n, f;
    cin >> n >> f;
    n = n - n % 100;
    
    int i;
    for (i = 0; i < 100; i++)
        if ((n + i) % f == 0) break;   
    
    if (i < 10) cout << "0";
    cout << i << "\n";
    
    return 0;
}