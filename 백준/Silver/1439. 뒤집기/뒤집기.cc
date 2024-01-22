#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int zero = 0, one = 0;
    char temp = s[0];
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == temp) continue;
        
        if (temp == '0') {
            zero++;
            temp = '1';
        }
        else {
            one++;
            temp = '0';
        } 
    }
    
    if (temp == '0') zero++;
    else one++;
    
    cout << min(zero, one) << "\n";
    
    return 0;
}