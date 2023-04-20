#include <iostream>
using namespace std;

int main() {
    double a, b;
    cin >> a >> b;
    cout << (a * (100 - b) / 100 < 100 ? 1 : 0) << "\n";
    return 0;
}