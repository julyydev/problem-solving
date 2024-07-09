#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << max(a + c, b) << "\n";
    return 0;
}