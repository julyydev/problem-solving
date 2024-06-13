#include <iostream>
using namespace std;

int main() {
    const int INF = 100000000;
    int n, x, y, min_x = INF, min_y = INF, max_x = -INF, max_y = -INF;
    cin >> n;
    
    while (n--) {
        cin >> x >> y;
        min_x = min(min_x, x);
        min_y = min(min_y, y);
        max_x = max(max_x, x);
        max_y = max(max_y, y);
    }
    
    cout << (max_x - min_x) * (max_y - min_y) << "\n";
    
    return 0;
}