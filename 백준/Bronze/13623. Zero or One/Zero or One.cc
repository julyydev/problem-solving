#include <iostream>
using namespace std;

int main() {
    int a, b, c, value;
    cin >> a >> b >> c;
    value = 4 * a + 2 * b + c;

    if (value == 3 || value == 4)
        cout << "A\n";
    else if (value == 2 || value == 5)
        cout << "B\n";
    else if (value == 1 || value == 6)
        cout << "C\n";
    else
        cout << "*\n";

    return 0;
}