#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int n, l;
    cin >> n >> l;

    string s;
    int max_black = 0, count = 0;
    while (n--) {
        cin >> s;

        int black = 0;
        bool is_black = false;
        for (int i = 0; i < l; i++) {
            if (s[i] == '0') {
                if (is_black) black++;
                is_black = false;
            } else {
                is_black = true;
            }
        }
        if (is_black) black++;

        if (black > max_black) {
            max_black = black;
            count = 1;
        } else if (black == max_black) {
            count++;
        }
    }
    cout << max_black << " " << count << "\n";

    return 0;
}