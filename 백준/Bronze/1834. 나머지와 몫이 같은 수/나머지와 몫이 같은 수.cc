#include <iostream>
using namespace std;

int main() {
    unsigned long long n;
    cin >> n;
    cout << n * (n + 1) * (n - 1) / 2 << "\n";
    return 0;
}