#include <iostream>
using namespace std;

int main() {
    int a, b, t;
    cin >> a >> b;
    t = (a + b) % 12;
    if (t == 0) t = 12;
    cout << t << '\n';
    
    return 0;
}