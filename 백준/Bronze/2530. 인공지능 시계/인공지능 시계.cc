#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a = a + d / 3600;
    d %= 3600;
    b = b + d / 60;
    d %= 60;
    c = c + d % 60;

    if (c >= 60) {
        c %= 60;
        b++;
    }
    if (b >= 60) {
        b %= 60;
        a++;
    }
    if (a >= 24) {
        a %= 24;
    }

    cout << a << " " << b << " " << c << "\n";

    return 0;
}