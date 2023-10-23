#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int n;
    cin >> n;

    cout << fixed;
    cout.precision(2);
    double d, f, p;
    while (n--) {
        cin >> d >> f >> p;
        cout << "$" << d * f * p << "\n";
    }

    return 0;
}