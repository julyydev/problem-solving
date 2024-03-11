#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int n;
    cin >> n;
    cin.ignore();

    string s;
    while (n--) {
        getline(cin, s);
        s[0] += (s[0] >= 'a' && s[0] <= 'z' ? 'A' - 'a' : 0);
        cout << s << "\n";
    }

    return 0;
}