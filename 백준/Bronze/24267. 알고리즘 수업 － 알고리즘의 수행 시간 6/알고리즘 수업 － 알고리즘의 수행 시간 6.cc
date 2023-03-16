#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    if (n == 1)
        cout << "0\n3\n";
    else
        cout << n * (n - 1) * (n - 2) / 6 << "\n3\n";

    return 0;
}