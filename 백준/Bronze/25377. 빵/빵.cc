#include <iostream>
using namespace std;

int main() {
    const int INF = 100000000;
    int n, a, b, min_time = INF;
    cin >> n;
    
    while (n--) {
        cin >> a >> b;
        if (a <= b) min_time = min(min_time, b);
    }
    
    if (min_time == INF) {
        cout << -1 << "\n";
        return 0;
    }
    
    cout << min_time << "\n";
    return 0;
}