#include <cmath>
#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int a, b;
    cin >> a >> b;
    int ad = a % 4 == 0 ? a / 4 - 1 : a / 4,
        bd = b % 4 == 0 ? b / 4 - 1 : b / 4;
    int ar = a % 4 == 0 ? 4 : a % 4, br = b % 4 == 0 ? 4 : b % 4;
    cout << abs(ad - bd) + abs(ar - br) << "\n";

    return 0;
}