#include <iostream>
using namespace std;

int main() {
    int p[4], x, y, r, ans = 0;
    for (int i = 0; i < 4; i++) cin >> p[i];
    cin >> x >> y >> r;
    
    for (int i = 0; i < 4; i++){
        if (x == p[i]) ans = i + 1;
    }
    
    cout << ans << "\n";
    return 0;
}