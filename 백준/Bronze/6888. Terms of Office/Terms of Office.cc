#include <iostream>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    
    while (x <= y) {
        cout << "All positions change in year " << x << "\n";
        x += 60;
    }
    
    return 0;
}