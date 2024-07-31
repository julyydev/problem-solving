#include <iostream>
using namespace std;

const double PI = 3.141592;

int main() {
    double d1, d2;
    cin >> d1 >> d2;

    cout << fixed;
    cout.precision(6);
    cout << 2 * d1 + 2 * d2 * PI << "\n";
    
    return 0;
}