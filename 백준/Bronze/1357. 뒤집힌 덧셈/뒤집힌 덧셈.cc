#include <iostream>
#include <string>
using namespace std;

int rev(int x) {
    string s = to_string(x);
    int result = 0, digit = 1;
    
    for (int i = 0; i < s.length(); i++) {
        result += (s[i] - '0') * digit;
        digit *= 10;
    }
    
    return result;
}


int main() {
    int x, y;
    cin >> x >> y;
    cout << rev(rev(x) + rev(y)) << "\n";
    
    return 0;
}