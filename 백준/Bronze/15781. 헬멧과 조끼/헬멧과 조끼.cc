#include <iostream>
using namespace std;

int main() {
    int n, m, h, a, mh = 0, ma = 0;
    cin >> n >> m;
    
    while (n--) {
        cin >> h;
        mh = max(mh, h);
    }
    
    while (m--) {
        cin >> a;
        ma = max(ma, a);
    }
    
    cout << mh + ma << "\n";
    
    return 0;
}