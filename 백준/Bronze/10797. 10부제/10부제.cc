#include <iostream>
using namespace std;

int main() {
    int n, x, count = 0;
    cin >> n;
    for (int i = 0; i < 5; i++) {
        cin >> x;
        if (x == n) count++;
    }

    cout << count << "\n";

    return 0;
}