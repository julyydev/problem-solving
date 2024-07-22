#include <iostream>
using namespace std;

int main() {
    string s;
    int count = 0;
    cin >> s;
    
    for (auto c : s) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') count++;
    }
    cout << count << "\n";
    
    return 0;
}