#include <iostream>
using namespace std;

int main() {
    int n, count = 0;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        if (s.find("01") != string::npos || s.find("OI") != string::npos) count++;
    }

    cout << count;
    return 0;
}