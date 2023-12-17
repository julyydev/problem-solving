#include <iostream>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    for (int i = n - 5; i < n; i++)
        cout << s[i];
    cout << "\n";
    
    return 0;
}