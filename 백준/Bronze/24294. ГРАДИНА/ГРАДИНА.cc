#include <iostream>
using namespace std;

int main() {
    int w1, h1, w2, h2;
    cin >> w1 >> h1 >> w2 >> h2;
    cout << 4 + 2 * max(w1, w2) + 2 * (h1 + h2) << "\n";
    return 0;
}