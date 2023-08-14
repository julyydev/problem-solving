#include <iostream>
using namespace std;

int main() {
    int B, P;
    cin >> B;
    P = 5 * B - 400;

    cout << P << "\n";
    if (P < 100)
        cout << "1\n";
    else if (P > 100)
        cout << "-1\n";
    else
        cout << "0\n";

    return 0;
}