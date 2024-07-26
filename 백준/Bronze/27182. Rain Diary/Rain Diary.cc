#include <iostream>
using namespace std;

int main() {
    int x, y;
	cin >> x >> y;
    cout << (x > 7 ? x - 7 : y + 7) << "\n";
    return 0;
}