// https://www.acmicpc.net/problem/11655
// written by julyy

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    
    for (int i = 0; i < s.size(); i++) {
        if ((s[i] >= 'A' && s[i] <= 'Z' - 13) || (s[i] >= 'a' && s[i] <= 'z' - 13))
            s[i] += 13;
        else if ((s[i] >= 'Z' - 12 && s[i] <= 'Z') || (s[i] >= 'z' - 12 && s[i] <= 'z'))
            s[i] -= 13;
    }
    cout << s;
    
    return 0;
}
