#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << min(4 * a + 2 * b, min(2 * a + 2 * c, 2 * b + 4 * c)) << "\n";
    return 0;
}