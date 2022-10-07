// https://www.acmicpc.net/problem/10953
// written by julyy

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    string s;
    
    for (int i = 0; i < t; i++) {
        cin >> s;
        cout << s[0] - '0' + s[2] - '0' << '\n';
    }
    
    return 0;
}
