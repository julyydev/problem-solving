#include <iostream>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    long long t, n;
    cin >> t;
    
    while (t--) {
        cin >> n;
        cout << n * n << "\n";
    }
    
    return 0;
}