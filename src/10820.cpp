// https://www.acmicpc.net/problem/10820
// written by julyy

#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    while (getline(cin, s)) {
        int count[4] = {0, };
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z')
                count[0]++;
            else if (s[i] >= 'A' && s[i] <= 'Z')
                count[1]++;
            else if (s[i] >= '0' && s[i] <= '9')
                count[2]++;
            else if (s[i] == ' ')
                count[3]++;
        }

        for (int i = 0; i < 4; i++)
            cout << count[i] << ' ';
        cout << '\n';
    }
    
    return 0;
}
