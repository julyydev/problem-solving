#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int n;
    while (1) {
        cin >> n;
        if (n == -1) break;

        vector<int> divisor;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                divisor.push_back(i);
                if (i != 1 && i * i != n) divisor.push_back(n / i);
            }
        }

        if (n == accumulate(divisor.begin(), divisor.end(), 0)) {
            sort(divisor.begin(), divisor.end());
            int i;
            cout << n << " = ";
            for (i = 0; i < divisor.size() - 1; i++)
                cout << divisor[i] << " + ";
            cout << divisor[i] << "\n";
        } else
            cout << n << " is NOT perfect.\n";
    }

    return 0;
}