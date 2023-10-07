#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

const int MAX = 1000001;

int main() {
    FASTIO();
    int n, x;
    cin >> n;

    vector<int> card(n);
    vector<bool> check(MAX, false);
    vector<int> score(MAX, 0);
    for (int i = 0; i < n; i++) {
        cin >> x;
        card[i] = x;
        check[x] = true;
    }

    for (int i = 1; i < MAX; i++) {
        if (!check[i]) continue;

        for (int j = i * 2; j < MAX; j += i) {
            if (check[j]) {
                score[i]++;
                score[j]--;
            }
        }
    }

    for (int i = 0; i < n; i++) cout << score[card[i]] << " ";

    cout << "\n";

    return 0;
}