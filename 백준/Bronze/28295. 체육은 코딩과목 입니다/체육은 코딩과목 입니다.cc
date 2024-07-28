#include <iostream>
using namespace std;

const char direction[4] = {'N', 'E', 'S', 'W'};

int main() {
    int t, d = 0;
    for (int i = 0; i < 10; i++) {
        cin >> t;
        d = (d + t) % 4;
    }
    cout << direction[d] << "\n";
    
    return 0;
}