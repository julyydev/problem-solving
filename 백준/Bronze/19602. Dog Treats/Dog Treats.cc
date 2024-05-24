#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << (a + 2 * b + 3 * c >= 10 ? "happy" : "sad") << '\n';
    return 0;
}