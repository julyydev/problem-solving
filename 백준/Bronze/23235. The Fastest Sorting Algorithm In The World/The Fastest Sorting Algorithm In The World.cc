#include <iostream>
using namespace std;

int main() {
    int index = 1, n, x;
    while (1) {
        cin >> n;
        if (n == 0) break;
        
        for (int i = 0; i < n; i++) cin >> x;
        cout << "Case " << index++ << ": Sorting... done!\n";
    }
    
    return 0;
}