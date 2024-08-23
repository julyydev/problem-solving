#include <iostream>
using namespace std;

int main() {
    int s, a, b;
    cin >> s >> a >> b;
    cout << 250 + 100 * (max(s - a, 0) / b + (max(s - a, 0) % b > 0 ? 1 : 0)) << "\n";
    return 0;
}