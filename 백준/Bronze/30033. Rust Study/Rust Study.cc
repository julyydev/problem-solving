#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, p, count = 0;
    cin >> n;
    
    vector<int> pages(n);
    for (int i = 0; i < n; i++) cin >> pages[i];
    
    for (int i = 0; i < n; i++) {
        cin >> p;
        if (p >= pages[i]) count++;
    }
    
    cout << count << "\n";
    
    return 0;
}