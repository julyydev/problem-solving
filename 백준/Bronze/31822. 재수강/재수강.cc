#include <iostream>
using namespace std;

int main() {
    string t;
    int n;
    cin >> t >> n;
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        
        int j;
        for (j = 0; j < 5; j++)
            if (t[j] != s[j]) break;
           
        if (j == 5) count++;
    }
    
    cout << count << "\n";
    
    return 0;
}