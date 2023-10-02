#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int a, b, c;
    while (1) {
        cin >> a >> b >> c;
        if (a == 0) break;

        if (a >= b + c || b >= a + c || c >= a + b) {
            cout << "Invalid\n";
            continue;
        }

        if (a == b && b == c)
            cout << "Equilateral\n";
        else if (a == b || b == c || c == a)
            cout << "Isosceles\n";
        else
            cout << "Scalene\n";
    }

    return 0;
}