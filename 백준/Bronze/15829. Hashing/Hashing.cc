#include <iostream>
using namespace std;

int main() {
    int L, hash = 0, m = 1;
    char c;

    cin >> L;
    for (int i = 0; i < L; i++) {
        cin >> c;
        hash += m * (c - 'a' + 1);
        m *= 31;
    }
    cout << hash << '\n';

    return 0;
}