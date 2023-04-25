#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    string s, target, result = "";
    cin >> s >> target;

    for (int i = 0; i < s.length(); i++) {
        result += s[i];

        if (result.length() < target.length()) continue;
        if (result.substr(result.length() - target.length(), target.length()) ==
            target) {
            for (int j = 0; j < target.length(); j++) result.pop_back();
        }
    }

    if (result == "")
        cout << "FRULA\n";
    else
        cout << result << "\n";

    return 0;
}