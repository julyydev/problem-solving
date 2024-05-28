#include <iostream>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    if (s[n - 1] == 'G') {
        for (int i = 0; i < n - 1; i++) cout << s[i];
        cout << "\n";
    } else {
        cout << s << "G\n";
    }
    
    return 0;
}