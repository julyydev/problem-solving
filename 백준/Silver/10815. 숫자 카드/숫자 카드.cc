#include <iostream>
#include <unordered_set>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    unordered_set<int> us;
    int n, m, x;
    cin >> n;
    while (n--) {
        cin >> x;
        us.insert(x);
    }

    cin >> m;
    while (m--) {
        cin >> x;
        cout << (us.find(x) != us.end()) << " ";
    }
    cout << "\n";

    return 0;
}