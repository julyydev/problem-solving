#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a > b + 1) cout << 2 * b + 1 << "\n";
    else cout << 2 * a - 1 << "\n";
    return 0;
}