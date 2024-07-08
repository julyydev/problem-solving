#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << (c >= a && c < b ? 1 : 0) << "\n";
    return 0;
}