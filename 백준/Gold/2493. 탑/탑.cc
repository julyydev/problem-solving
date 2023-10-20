#include <iostream>
#include <stack>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Data {
    int index, value;
    Data(int index, int value) : index(index), value(value) {}
};

int main() {
    FASTIO();
    stack<Data> s;

    int n, h, top = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h;
        while (!s.empty() && h > s.top().value) s.pop();
        if (s.empty())
            cout << 0 << " ";
        else
            cout << s.top().index << " ";
        s.push({i, h});
    }
    cout << "\n";

    return 0;
}