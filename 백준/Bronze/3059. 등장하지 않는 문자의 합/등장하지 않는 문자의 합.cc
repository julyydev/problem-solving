#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int t;
    cin >> t;

    while (t--) {
        vector<bool> check(26, false);
        string s;
        cin >> s;

        for (auto c : s) check[c - 'A'] = true;

        int sum = 0;
        for (int i = 0; i < 26; i++)
            if (!check[i]) sum += 65 + i;
        cout << sum << "\n";
    }

    return 0;
}