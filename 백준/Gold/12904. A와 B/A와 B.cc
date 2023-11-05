#include <algorithm>
#include <iostream>
using namespace std;

bool can_change(const string& s, const string& t) {
    string temp = t;
    while (temp.length() > s.length()) {
        char back = temp.back();
        temp.pop_back();
        if (back == 'B') reverse(temp.begin(), temp.end());
    }

    return s == temp;
}

int main() {
    string s, t;
    cin >> s >> t;
    cout << can_change(s, t) << "\n";

    return 0;
}