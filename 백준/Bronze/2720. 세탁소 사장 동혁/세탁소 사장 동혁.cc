#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int T, C;
    cin >> T;

    while (T--) {
        cin >> C;
        cout << C / 25 << " ";
        C %= 25;
        cout << C / 10 << " ";
        C %= 10;
        cout << C / 5 << " ";
        C %= 5;
        cout << C << "\n";
    }

    return 0;
}