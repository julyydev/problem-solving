#include <iostream>
using namespace std;

int main() {
    int n, m, num = 0;
    cin >> n >> m;
    
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        int count = 0;
        for (auto c : s)
            if (c == 'O') count++;
        
        if (count >= (m + 1) / 2) num++;
    }
    cout << num << '\n';
    
    return 0;
}