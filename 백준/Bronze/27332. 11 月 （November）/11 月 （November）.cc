#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int d = a + 7 * b;
    cout << (d >= 1 && d <= 30 ? 1 : 0) << "\n";

    return 0;
}