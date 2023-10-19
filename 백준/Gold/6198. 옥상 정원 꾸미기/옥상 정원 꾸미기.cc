#include <iostream>
#include <stack>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    stack<int> s;

    int n, h;
    long long sum = 0;
    cin >> n;
    while (n--) {
        cin >> h;
        while (!s.empty() && h >= s.top()) s.pop();
        sum += s.size();
        s.push(h);
    }

    cout << sum << "\n";

    return 0;
}