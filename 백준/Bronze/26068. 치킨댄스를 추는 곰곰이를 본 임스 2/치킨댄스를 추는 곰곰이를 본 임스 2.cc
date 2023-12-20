#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    char a, b;
    int day, count = 0;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> day;
        if (day <= 90) count++;
    }
    
    cout << count << "\n";
    
    return 0;
}