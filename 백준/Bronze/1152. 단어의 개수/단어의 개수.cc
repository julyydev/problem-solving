// https://www.acmicpc.net/problem/1152
// written by julyy

#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    getline(cin, str);
    if (str.empty()) {
        cout << "0\n";
    }
    else {
        int count = 1;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == ' ')
                 count++;
        }
        if (str[0] == ' ')
            count--;
        if (str[str.length() - 1] == ' ')
            count--;
        cout << count << '\n';
    }

    return 0;
}
