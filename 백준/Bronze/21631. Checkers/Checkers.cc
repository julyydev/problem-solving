#include <iostream>
using namespace std;

int main() {
    long long w, b;
    cin >> w >> b;
    cout << (w >= b ? b : w + 1) << "\n";
    return 0;
}