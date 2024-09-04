#include <iostream>
using namespace std;

int main() {
    long long p1, q1, p2, q2;
    cin >> p1 >> q1 >> p2 >> q2;
    cout << (p1 * p2 % (2 * q1 * q2) == 0 ? 1 : 0) << "\n";
    return 0;
}