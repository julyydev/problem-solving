#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    string s;
    bool check = false;
    for (int i = 1; i <= 5; i++) {
        cin >> s;
        if (s.find("FBI") != string::npos) {
            cout << i << " ";
            check = true;
        }
    }
    if (!check) cout << "HE GOT AWAY!";
    cout << "\n";

    return 0;
}