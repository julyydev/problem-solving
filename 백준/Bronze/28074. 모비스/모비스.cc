#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    string s;
    cin >> s;

    vector<bool> check(26, false);
    for (char c : s) check[c - 'A'] = true;

    bool able = true;
    string target = "MOBIS";
    for (char c : target)
        if (!check[c - 'A']) able = false;

    cout << (able ? "YES" : "NO") << "\n";

    return 0;
}