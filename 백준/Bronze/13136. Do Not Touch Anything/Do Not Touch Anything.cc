#include <iostream>
using namespace std;

int main() {
    long long r, c, n;
    cin >> r >> c >> n;
    cout << ((r / n + (r % n ? 1 : 0)) * (c / n + (c % n ? 1 : 0))) << "\n";
    return 0;
}