#include <iostream>
#define io() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int set = 0;

void add(int x) { set |= (1 << x); };

void remove(int x) { set &= ~(1 << x); };

bool check(int x) { return set & (1 << x); };

void toggle(int x) { set ^= (1 << x); };

void all() { set = (1 << 21) - 1; };

void empty() { set = 0; };

int main() {
    io();
    int M, x;
    string cmd;
    cin >> M;
    cin.ignore();

    for (int i = 0; i < M; i++) {
        cin >> cmd;
        if (cmd == "all") {
            all();
        } else if (cmd == "empty") {
            empty();
        } else {
            cin >> x;
            if (cmd == "add")
                add(x);
            else if (cmd == "remove")
                remove(x);
            else if (cmd == "check")
                cout << check(x) << "\n";
            else if (cmd == "toggle")
                toggle(x);
        }
    }

    return 0;
}