#include <iostream>
using namespace std;

int main() {
    int n, w, h, l;
    cin >> n >> w >> h;
    
    while (n--) {
        cin >> l;
        if (l * l <= w * w + h * h)
            cout << "DA\n";
        else
            cout << "NE\n";
    }
    
    return 0;
}