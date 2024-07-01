#include <iostream>
using namespace std;

int main() {
    int n, count = 0;
    string s, t;
    cin >> n >> s >> t;
    
    for (int i = 0; i < n; i++)
        if (s[i] != t[i]) count++;    
    cout << count << "\n";
    
    return 0;
}