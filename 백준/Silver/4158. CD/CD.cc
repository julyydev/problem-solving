#include <iostream>
#include <unordered_set>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;
 
int main() {
    FASTIO();
    
    int n, m, x;
    unordered_set<int> cd;
    
    while (1) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        
        cd.clear();
        for (int i = 0; i < n; i++) {
            cin >> x;
            cd.insert(x);
        }
    
        int count = 0;
        for (int i = 0; i < m; i++) {
            cin >> x;
            if (cd.find(x) != cd.end()) count++;
        }
        
        cout << count << "\n";
    }
        
    return 0;
}