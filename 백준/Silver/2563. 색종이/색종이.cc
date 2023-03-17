#include <cstring>
#include <iostream>
using namespace std;

int main() {
    int n, x, y, sum = 0;
    bool paper[100][100];
    memset(paper, false, sizeof(paper));
    cin >> n;

    while (n--) {
        cin >> x >> y;
        for (int i = x; i < x + 10; i++) {
            for (int j = y; j < y + 10; j++) {
                paper[i][j] = true;
            }
        }
    }

    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            if (paper[i][j]) sum++;

    cout << sum << "\n";

    return 0;
}