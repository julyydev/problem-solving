#include <iostream>
using namespace std;

int to_minute(int d, int h, int m) {
    return d * 24 * 60 + h * 60 + m;
}

int main() {
    int d, h, m;
    cin >> d >> h >> m;
    
    int gap = to_minute(d, h, m) - to_minute(11, 11, 11);
    cout << (gap >= 0 ? gap : -1) << '\n';
    
    return 0;
}