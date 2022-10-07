// https://www.acmicpc.net/problem/2908
// written by julyy

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    for (int i = 2; i >= 0; i--) {
        if (s1[i] < s2[i]) {
            cout << s2[2] << s2[1] << s2[0];
            break;
        }
        else if (s1[i] > s2[i]) {
            cout << s1[2] << s1[1] << s1[0];
            break;
        }
    }
}
