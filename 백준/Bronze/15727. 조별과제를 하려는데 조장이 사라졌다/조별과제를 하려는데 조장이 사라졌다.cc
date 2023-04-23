#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n % 5 == 0) {
        cout << n / 5 << "\n";
    } else {
        cout << n / 5 + 1 << "\n";
    }
    return 0;
}