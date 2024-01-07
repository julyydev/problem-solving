#include <iostream>
using namespace std;

int main() {
    int n, a, b, c;
    cin >> n;
    
    cout << "Gnomes:\n";
    while (n--) {
        cin >> a >> b >> c;
        if ((a < b && b < c) || (a > b && b > c))
            cout << "Ordered\n";
        else
            cout << "Unordered\n";
    }
    
    return 0;
}