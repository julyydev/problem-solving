#include <iostream>
using namespace std;

int main() {
    int n, x, s, t, max_time = -1;
    cin >> n >> x;
    
    for (int i = 0; i < n; i++) {
        cin >> s >> t;
        if (s + t > x) continue;
        max_time = max(max_time, s);
    }
    cout << max_time << "\n";
    
    return 0;
}