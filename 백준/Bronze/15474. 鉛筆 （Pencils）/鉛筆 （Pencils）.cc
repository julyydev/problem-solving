#include <iostream>
using namespace std;

int main() {
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    cout << min((n / a + (n % a > 0 ? 1 : 0)) * b, (n / c + (n % c > 0 ? 1 : 0)) * d) << "\n";
    return 0;
}