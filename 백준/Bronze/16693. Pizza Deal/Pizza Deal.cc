#include <iostream>

const double PI = 3.14159265359;

using namespace std;
int main() {
    double a, p1, r, p2;
    cin >> a >> p1 >> r >> p2;
    double whole = r * r * PI / p2;
    double slice = a / p1;
    
    cout << (whole > slice ? "Whole pizza" : "Slice of pizza") << "\n";
    return 0;
}