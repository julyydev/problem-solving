#include <iostream>
using namespace std;

int main() {
    int w, h;
    cin >> w >> h;
    
    cout << fixed;
    cout.precision(1);
    cout << (double)w * h / 2 << "\n";
    
    return 0;
}