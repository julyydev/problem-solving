#include <iostream>
using namespace std;

int main() {
    int n, count = 0;
    char c;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> c;
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            count++;
    }
    cout << count << "\n";
    
    return 0;
}