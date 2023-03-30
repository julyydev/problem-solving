#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    char c;
    for (int i = 0; i < s.length(); i++) {
        if (s.c_str()[i] >= 'A' && s.c_str()[i] <= 'Z')
            cout << (char)(s.c_str()[i] - 'A' + 'a');
        else
            cout << (char)(s.c_str()[i] - 'a' + 'A');
    }
    cout << "\n";

    return 0;
}