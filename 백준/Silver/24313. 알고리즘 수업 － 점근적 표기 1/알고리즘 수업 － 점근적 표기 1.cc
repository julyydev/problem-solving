#include <iostream>
using namespace std;

int main() {
    int a1, a2, c, n0;
    cin >> a1 >> a2 >> c >> n0;
    if (a1 * n0 + a2 <= c * n0 && c >= a1)
        cout << "1\n";
    else
        cout << "0\n";

    return 0;
}