#include <iostream>
using namespace std;

int main() {
    long long s;
    cin >> s;

    long long n = 1;
    while ((n + 1) * (n + 2) / 2 <= s) {
        n++;
    }
    cout << n << "\n";

    return 0;
}