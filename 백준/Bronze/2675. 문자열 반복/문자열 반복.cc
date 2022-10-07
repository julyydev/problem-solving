// https://www.acmicpc.net/problem/2675
// written by julyy

#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int r;
        string s;
        cin >> r >> s;

        for (int j = 0; j < s.length(); j++) {
            for (int k = 0; k < r; k++) {
                cout << s[j];
            }
        }
        cout << "\n";
    }    

    return 0;
}
