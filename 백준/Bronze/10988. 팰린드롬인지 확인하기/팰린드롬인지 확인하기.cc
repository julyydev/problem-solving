#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    string s, o;
    cin >> s;
    o = s;
    reverse(s.begin(), s.end());
    cout << (s.compare(o) == 0 ? 1 : 0) << "\n";

    return 0;
}