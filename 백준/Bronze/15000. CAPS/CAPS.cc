#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++) cout << (char)(s[i] - 'a' + 'A');
    cout << "\n";

    return 0;
}