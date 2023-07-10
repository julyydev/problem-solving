#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    string s, result = "";
    cin >> s;

    int i = 0;
    while (i < s.length()) {
        if (s[i] == '.') {
            result.push_back('.');
            i++;
            continue;
        }

        int start = i;
        while (s[i] == 'X') i++;

        int length = i - start;
        if (length % 2 != 0) {
            cout << "-1\n";
            return 0;
        }

        while (length) {
            if (length > 2) {
                result += "AAAA";
                length -= 4;
            } else {
                result += "BB";
                length -= 2;
            }
        }
    }
    cout << result << "\n";

    return 0;
}