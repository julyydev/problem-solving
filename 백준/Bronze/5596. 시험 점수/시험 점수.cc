#include <iostream>
using namespace std;

int main() {
    int s = 0, t = 0, x;

    for (int i = 0; i < 4; i++) {
        cin >> x;
        s += x;
    }

    for (int i = 0; i < 4; i++) {
        cin >> x;
        t += x;
    }

    cout << max(s, t) << "\n";

    return 0;
}