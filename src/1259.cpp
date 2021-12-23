// https://www.acmicpc.net/problem/1259
// written by julyy

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s, s_copy;
    while (1) {
        cin >> s;
        if (s == "0")
            break;
        
        s_copy = s;
        reverse(s.begin(), s.end());
        if (s == s_copy)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    
    return 0;
}
