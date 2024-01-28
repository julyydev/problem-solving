#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    string s;

    int t = 1;
    while (1) {
        cin >> s;
        if (s == "0") break;

        while (s.length() % 2 == 0) {
            string temp = "";
            for (int i = 0; i < s.length(); i += 2) {
                for (int j = 0; j < s[i] - '0'; j++) {
                    temp += s[i + 1];
                }
            }

            if (s == temp) break;
            s = temp;
        }

        cout << "Test " << t << ": " << s << "\n";
        t++;
    }

    return 0;
}