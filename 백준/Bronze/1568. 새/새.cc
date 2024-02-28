#include <iostream>
using namespace std;

int main() {
    int n, t = 0;
    cin >> n;
    
    int c = 1;
    while (n) {
        if (n < c) c = 1;
        n -= c;
        c++;
        t++;
    }
    
    cout << t << "\n";
    
    return 0;
}